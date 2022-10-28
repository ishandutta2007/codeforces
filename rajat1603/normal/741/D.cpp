#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n;
int p;
char c[4];
vector < pair < int , int > > v[N];
int ans[N];
bool done[N];
int subtree[N];
int depth[N];
const int MX = 1 << 22;
pair < int , int > mp[MX];
int last[MX];
int curr;
int cent;
inline int combine(int a , int b){
    if(depth[a] < depth[b]){
        return a;
    }
    return b;
}
inline void dfs1(int node , int mask , int len , int lc , int parent){
    if(last[mask] == curr){
        auto it = mp[mask];
        int val = len + it.first;
        int lca = combine(lc , it.second);
        if(ans[lca] < val){
            ans[lca] = val;
        }
    }
    for(int i = 0 ; i < 22 ; ++i){
        if(last[mask ^ (1 << i)] == curr){
            auto it = mp[mask ^ (1 << i)];
            int val = len + it.first;
            int lca = combine(lc , it.second);
            if(val > ans[lca]){
                ans[lca] = val;
            }
        }
    }
    for(auto it : v[node]){
        int next = it.first;
        if(next != parent && !done[next]){
            dfs1(next , mask ^ (1 << (it.second - 'a')) , len + 1 , combine(lc , next) , node);
        }
    }
}
inline void dfs2(int node , int mask , int len , int lc , int parent){
    if(last[mask] != curr){
        last[mask] = curr;
        mp[mask] = make_pair(len , lc);
    }
    else if(mp[mask].first < len){
        mp[mask] = make_pair(len , lc);
    }
    for(auto it : v[node]){
        int next = it.first;
        if(next != parent && !done[next]){
            dfs2(next , mask ^ (1 << (it.second - 'a')) , len + 1 , combine(lc , next) , node);
        }
    }
}
inline void getans(int node){
    ++curr;
    last[0] = curr;
    mp[0] = make_pair(0 , node);
    for(auto it : v[node]){
        if(!done[it.first]){
            dfs1(it.first , 1 << (it.second - 'a') , 1 , combine(node , it.first) , node);
            dfs2(it.first , 1 << (it.second - 'a') , 1 , combine(node , it.first) , node);
        }
    }
    ++curr;
    last[0] = curr;
    mp[0] = make_pair(0 , node);
    reverse(v[node].begin() , v[node].end());
    for(auto it : v[node]){
        if(!done[it.first]){
            dfs1(it.first , 1 << (it.second - 'a') , 1 , combine(node , it.first) , node);
            dfs2(it.first , 1 << (it.second - 'a') , 1 , combine(node , it.first) , node);
        }
    }
}
inline int find(int node , int val , int parent){
    for(auto next : v[node]){
        if(next.first != parent && !done[next.first] && subtree[next.first] > val){
            return find(next.first , val , node);
        }
    }
    return node;
}
inline void dfs(int node , int parent){
    subtree[node] = 1;
    for(auto next : v[node]){
        if(next.first != parent && !done[next.first]){
            dfs(next.first , node);
            subtree[node] += subtree[next.first];
        }
    }
}
void solve(int node){
    dfs(node , 0);
    cent = find(node , subtree[node] >> 1 , 0);
    getans(cent);
    done[cent] = 1;
    for(auto next : v[cent]){
        if(!done[next.first]){
            solve(next.first);
        }
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 2 ; i <= n ; ++i){
        scanf("%d %s" , &p , c);
        v[p].emplace_back(make_pair(i , c[0]));
        v[i].emplace_back(make_pair(p , c[0]));
        depth[i] = depth[p] + 1;
    }
    solve(1);
    for(int i = n ; i >= 1 ; --i){
        for(auto it : v[i]){
            if(it.first > i){
                ans[i] = max(ans[i] , ans[it.first]);
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , ans[i] , " \n"[i == n]);
    }
}