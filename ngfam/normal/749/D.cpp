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
const llint N = 2e5 + 1, mod = 1e9 + 7;
typedef pair<int,int> ii;

priority_queue < ii > pq;
vector < int > cash[N];

int n, q, m, ok[N];

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int u, v; scanf("%d%d", &u, &v);
        cash[u].push_back(v);
        m = max(m, u);
    }

    for(int i = 1; i <= m; ++i){
        if(cash[i].size() > 0){
            sort(cash[i].begin(), cash[i].end());
            pq.push(ii(cash[i][cash[i].size() - 1], i));
        }
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; ++i){
        vector < int > vertice;
        vector < ii > out;

        int len; scanf("%d", &len);
        for(int i = 1; i <= len; ++i){
            int u; scanf("%d", &u);
            ok[u] = 1;
            vertice.push_back(u);
        }

        while(!pq.empty() && ok[pq.top().second]){
            out.push_back(pq.top());
            pq.pop();
        }
        if(pq.empty()){
            printf("0 0\n");
            for(int j = 0; j < out.size(); ++j){
                pq.push(out[j]);
            }
         for(int j = 0; j < vertice.size(); ++j){
            ok[vertice[j]] = 0;
        }
            continue;
        }

        int winner = pq.top().second;



        if(pq.size() == 1){
            printf("%d %d\n", winner, cash[winner][0]);
            for(int j = 0; j < out.size(); ++j){
                pq.push(out[j]);
            }
            for(int j = 0; j < vertice.size(); ++j){
            ok[vertice[j]] = 0;
        }
            continue;

        }

        out.push_back(pq.top());
        pq.pop();
        while(!pq.empty() && ok[pq.top().second]){
            out.push_back(pq.top());
            pq.pop();
        }


        if(pq.size() == 0){
            printf("%d %d\n", winner, cash[winner][0]);
            for(int j = 0; j < out.size(); ++j){
                pq.push(out[j]);
            }
            for(int j = 0; j < vertice.size(); ++j){
            ok[vertice[j]] = 0;
            }
            continue;
        }

        int fin = upper_bound(cash[winner].begin(), cash[winner].end(), pq.top().first) - cash[winner].begin();
        printf("%d %d\n", winner, cash[winner][fin]);
        for(int j = 0; j < out.size(); ++j){
            pq.push(out[j]);
        }
        for(int j = 0; j < vertice.size(); ++j){
            ok[vertice[j]] = 0;
        }
    }
}