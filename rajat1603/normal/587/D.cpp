#include "bits/stdc++.h"
using namespace std;
const int N = 6e5 + 10;
const int H = N >> 1;
int n , m;
struct edge{
    int a , b , c , t , idx;
    bool operator < (const edge &other) const {
        return t < other.t;
    }
    void read(){
        scanf("%d %d %d %d" , &a , &b , &c , &t);
    }
};
edge arr[N];
vector < int > v[N];
int cur;
vector < int > g[N];
int tin[N];
int anc[N];
int ins[N];
int stk[N];
int siz;
int cmp;
int tim;
int scc[N];
vector < int > ans;
void dfs(int node){
    tin[node] = anc[node] = ++tim;
    stk[++siz] = node;
    ins[node] = 1;
    for(int next : g[node]){
        if(!tin[next]){
            dfs(next);
            anc[node] = min(anc[node] , anc[next]);
        }
        else if(ins[next]){
            anc[node] = min(anc[node] , tin[next]);
        }
    }
    if(tin[node] == anc[node]){
        int tmp;
        ++cmp;
        do{
            tmp = stk[siz--];
            ins[tmp] = 0;
            scc[tmp] = cmp;
        }
        while(tmp != node);
    }
}
inline int neg(int x){
    if(x <= H){
        return x + H;
    }
    return x - H;
}
vector < int > h[N];
int indeg[N];
int pos[N];
void toposort(){
    for(int i = 1 ; i < N ; ++i){
        for(int j : g[i]){
            if(scc[i] != scc[j]){
                h[scc[i]].emplace_back(scc[j]);
                ++indeg[scc[j]];
            }
        }
    }
    queue < int > q;
    for(int i = 1 ; i < N ; ++i){
        if(!indeg[i]){
            q.push(i);
        }
    }
    int num = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        pos[node] = ++num;
        for(int next : h[node]){
            --indeg[next];
            if(!indeg[next]){
                q.push(next);
            }
        }
    }
}
bool check(int idx , bool print){
    for(int i = 0 ; i < N ; ++i){
        g[i].clear();
        tin[i] = 0;
        anc[i] = 0;
        ins[i] = 0;
        stk[i] = 0;
    }
    tim = 0;
    siz = 0;
    cmp = 0;
    cur = m;
    for(int i = idx + 1 ; i <= m ; ++i){
        g[neg(i)].emplace_back(i);
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 2 ; j < v[i].size() ; ++j){
            if(arr[v[i][j - 2]].c == arr[v[i][j]].c){
                return 0;
            }
        }
        for(int j = 1 ; j < v[i].size() ; ++j){
            int a = v[i][j - 1];
            int b = v[i][j];
            if(arr[a].c == arr[b].c){
                g[a].emplace_back(neg(b));
                g[b].emplace_back(neg(a));
            }
        }
        ++cur;
        for(int j = 0 ; j < v[i].size() ; ++j){
            int node = v[i][j];
            g[neg(node)].emplace_back(cur);
            g[neg(cur)].emplace_back(node);
            ++cur;
            g[cur].emplace_back(node);
            g[neg(node)].emplace_back(neg(cur));
            g[cur].emplace_back(cur - 1);
            g[neg(cur - 1)].emplace_back(neg(cur));
        }
    }
    for(int i = 1 ; i <= cur ; ++i){
        if(!tin[i]){
            dfs(i);
        }
    }
    for(int i = 1 ; i <= cur ; ++i){
        if(!tin[neg(i)]){
            dfs(neg(i));
        }
    }
    for(int i = 1 ; i <= cur ; ++i){
        if(scc[i] == scc[neg(i)]){
            return 0;
        }
    }
    if(print){
        toposort();
        for(int i = 1 ; i <= m ; ++i){
            if(pos[scc[i]] < pos[scc[neg(i)]]){
                ans.emplace_back(i);
            }
        }
    }
    return 1;
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        arr[i].read();
        arr[i].idx = i;
    }
    sort(arr + 1 , arr + 1 + m);
    for(int i = 1 ; i <= m ; ++i){
        v[arr[i].a].emplace_back(i);
        v[arr[i].b].emplace_back(i);
    }
    for(int i = 1 ; i <= n ; ++i){
        sort(v[i].begin() , v[i].end() , [](int a , int b){
            return arr[a].c < arr[b].c;
        });
    }
    if(check(m , 0)){
        printf("Yes\n");
        int l = 0;
        int r = m;
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid , 0)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        check(l , 1);
        printf("%d %d\n" , arr[l].t , int(ans.size()));
        for(int x : ans){
            printf("%d " , arr[x].idx);
        }
        printf("\n");
    }
    else{
        printf("No\n");
        return 0;
    }
}