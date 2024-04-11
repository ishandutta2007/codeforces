#include "bits/stdc++.h"
using namespace std;
const int N = 4e3 + 3;
const int SN = N;
int n;
char a[N] , b[N];
string fst[N];
string snd[N];
int neg(int x){
    if(x <= n){
        return x + n;
    }
    return x - n;
}
vector < int > v[N];
int tin[N];
int anc[N];
int ins[N];
int stk[N];
int siz;
int cur;
int tim;
int scc[N];
void dfs(int node){
    tin[node] = anc[node] = ++tim;
    stk[++siz] = node;
    ins[node] = 1;
    for(int next : v[node]){
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
        ++cur;
        while(tmp != node){
            tmp = stk[siz--];
            ins[tmp] = 0;
            scc[tmp] = cur;
        };
    }
}
vector < int > g[N];
int indeg[N];
int pos[N];
void toposort(){
    for(int i = 1 ; i <= n + n ; ++i){
        for(int j : v[i]){
            if(scc[i] != scc[j]){
                g[scc[i]].emplace_back(scc[j]);
                ++indeg[scc[j]];
            }
        }
    }
    queue < int > q;
    for(int i = 1 ; i <= cur ; ++i){
        if(!indeg[i]){
            q.push(i);
        }
    }
    int num = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        pos[node] = ++num;
        for(int next : g[node]){
            --indeg[next];
            if(!indeg[next]){
                q.push(next);
            }
        }
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , a);
        scanf("%s" , b);
        fst[i] = "";
        snd[i] = "";
        fst[i] += a[0];
        fst[i] += a[1];
        fst[i] += a[2];
        snd[i] += a[0];
        snd[i] += a[1];
        snd[i] += b[0];
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            if(fst[i] == fst[j]){
                v[i].emplace_back(i + n);
                v[j].emplace_back(j + n);
                //v[i].emplace_back(j + n);
                //v[j].emplace_back(i + n);
            }
            if(fst[i] == snd[j]){
                v[i].emplace_back(j);
                v[j + n].emplace_back(i + n);
            }
            if(snd[i] == fst[j]){
                v[i + n].emplace_back(j + n);
                v[j].emplace_back(i);
            }
            if(snd[i] == snd[j]){
                v[i + n].emplace_back(j);
                v[j + n].emplace_back(i);
            }
        }
    }
    for(int i = 1 ; i <= n + n ; ++i){
        if(!tin[i]){
            dfs(i);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(scc[i] == scc[i + n]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    toposort();
    for(int i = 1 ; i <= n ; ++i){
        if(pos[scc[i]] < pos[scc[i + n]]){
            cout << snd[i] << "\n";
        }
        else{
            cout << fst[i] << "\n";
        }
    }
}