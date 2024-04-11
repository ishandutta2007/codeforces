/*** Riven is not just my life :) ***/

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 2e5 + 10, mod = 1e9 + 7;

int n, a[N], t, k, b[N];
vector < int > vertice[N], adj[N];

void MAIN(){
    scanf("%d%d%d", &n, &t, &k);
    for(int i = 1; i <= t; ++i){
        scanf("%d", a + i);
    }

    for(int i = 2; i <= t + 1; ++i){
        if(a[i - 1] > a[i]){
            k -= a[i - 1] - a[i];
        }
    }

    if(k < 0){
        puts("-1");
        return;
    }

    int id = 1;
    for(int i = 1; i <= a[t]; ++i){
        vertice[t].push_back(++id);
    }

    for(int i = t - 1; i >= 1; --i){
        for(int j = 0; j < a[i]; ++j){
            vertice[i].push_back(++id);
        }
        //cerr << i << " : " << k << endl;
        if(k == 0){
            for(int u = 0; u < min(vertice[i].size(), vertice[i + 1].size()); ++u){
                adj[vertice[i][u]].push_back(vertice[i + 1][u]);
            }
            if(vertice[i].size() < vertice[i + 1].size()){
                for(int u = vertice[i].size(); u < vertice[i + 1].size(); ++u){
                    adj[vertice[i][0]].push_back(vertice[i + 1][u]);
                }
            }
        }
        else{
            int nodes = vertice[i].size() - max(0, a[i] - a[i + 1]);
            int alone = min(int(nodes) - 1, k);
            //cerr << "CURRR : " << i << endl;
            for(int j = 0; j < min(int(vertice[i + 1].size()), nodes - alone); ++j){
                adj[vertice[i][j]].push_back(vertice[i + 1][j]);
            }
            for(int j = nodes - alone; j < vertice[i + 1].size(); ++j){
                adj[vertice[i][0]].push_back(vertice[i + 1][j]);
            }
            k -= alone;
        }
    }

    for(int i = 0; i < vertice[1].size(); ++i){
        adj[1].push_back(vertice[1][i]);
    }

    if(k > 0){
        puts("-1");
        return;
    }
    printf("%d\n", n);
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < adj[i].size(); ++j){
            printf("%d %d\n", i, adj[i][j]);
        }
    }
}