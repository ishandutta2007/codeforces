#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
int a[N] , b[N];
vector < int > v[N];
vector < int > g[N];
vector < int > who[N];
int cur;
stack < int > s;
int start[N];
int iiiii;
vector < int > arr;
bool mark[N];
int col[N];
int subtree[N];
void dfs1(int node , int parent){
    subtree[node] = 1;
    for(int next : g[node]){
        if(next == parent){
            continue;
        }
        if(next == node){
            continue;
        }
        if(mark[next]){
            continue;
        }
        dfs1(next , node);
        subtree[node] += subtree[next];
    }
}
int find(int node , int parent , int val){
    for(int next : g[node]){
        if(next == parent){
            continue;
        }
        if(next == node){
            continue;
        }
        if(mark[next]){
            continue;
        }
        if(subtree[next] > val){
            return find(next , node , val);
        }
    }
    return node;
}
void dfs(int node , int level){
    dfs1(node , 0);
    int cent = find(node , 0 , subtree[node] >> 1);
    col[cent] = level;
    mark[cent] = 1;
    for(int next : g[cent]){
        if(mark[next]){
            continue;
        }
        dfs(next , level + 1);
    }
}
bool cmp(int a , int b){
    if(a > iiiii && b > iiiii){
        return a < b;
    }
    else if(a > iiiii && b < iiiii){
        return true;
    }
    else if(b > iiiii && a < iiiii){
        return false;
    }
    else{
        return a < b;
    }
}
bool cmp2(int a , int b){
    int x = who[a].size();
    int y = who[b].size();
    for(int i = 0 ; i < min(x , y) ; ++i){
        if(who[b][i] > who[a][i]){
            return 1;
        }
        if(who[a][i] > who[b][i]){
            return 0;
        }
    }
    return x < y;
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        v[i].clear();
        who[i].clear();
        g[i].clear();
        start[i] = -1;
    }
    cur = 0;
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , a + i , b + i);
        if(a[i] > b[i]){
            swap(a[i] , b[i]);
        }
        v[a[i]].emplace_back(b[i]);
        v[b[i]].emplace_back(a[i]);
    }
    for(int i = 1 ; i <= n ; ++i){
        iiiii = i;
        sort(v[i].begin() , v[i].end() , cmp);
        reverse(v[i].begin() , v[i].end());
    }
    while(!s.empty()){
        s.pop();
    }
    s.push(0);
    for(int i = 1 ; i <= n ; ++i){
        if(!v[i].empty()){
            who[s.top()].emplace_back(i);
            for(int x : v[i]){
                if(x == start[s.top()]){
                    int lol = s.top();
                    s.pop();
                    g[lol].emplace_back(s.top());
                    g[s.top()].emplace_back(lol);
                    who[s.top()].emplace_back(i);
                }
                else{
                    ++cur;
                    g[cur].emplace_back(s.top());
                    g[s.top()].emplace_back(s.top());
                    s.push(cur);
                    who[cur].emplace_back(i);
                    start[cur] = i;
                }
            }
        }
        else{
            who[s.top()].emplace_back(i);
        }
    }
    for(int i = 1 ; i <= n && s.top() != 0 ; ++i){
        if(!v[i].empty()){
            who[s.top()].emplace_back(i);
            for(int x : v[i]){
                if(x == start[s.top()]){
                    int lol = s.top();
                    s.pop();
                    g[lol].emplace_back(s.top());
                    g[s.top()].emplace_back(lol);
                    who[s.top()].emplace_back(i);
                }
            }
        }
        else{
            who[s.top()].emplace_back(i);
        }
    }
    for(int i = 0 ; i <= cur ; ++i){
        sort(who[i].begin() , who[i].end());
        who[i].resize(unique(who[i].begin() , who[i].end()) - who[i].begin());
        reverse(who[i].begin() , who[i].end());
        sort(g[i].begin() , g[i].end());
        g[i].resize(unique(g[i].begin() , g[i].end()) - g[i].begin());
    }
    arr.clear();
    for(int i = 0 ; i <= cur ; ++i){
        arr.emplace_back(i);
    }
    sort(arr.begin() , arr.end() , cmp2);
    for(int i = 1 ; i <= n ; ++i){
        mark[i] = 0;
        col[i] = 0;
    }
    dfs(0 , 1);
    for(int i = 0 ; i <= cur ; ++i){
        printf("%d%c" , col[arr[i]] , " \n"[i == n]);
    }
}