/* Riven is not just my life :) */

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
const llint N = 1e6 + 1, mod = 1e9 + 7;
int n, m, cnt[30], total[30], steal[N], par[N], inf[N];

vector < int > calc, adj[N];

struct ii{
    int first;
    int second;
    int id;
}a[N], ans[N];

queue < int > unf;
pair < int, int > idx[N];

void MAIN(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &a[i].first, &a[i].second);
        a[i].id = i;
        if(a[i].first == 1){
            unf.push(i);
        }
    }

    int sl = 0;

    while(!unf.empty()){
        int u = unf.front(); unf.pop();
        if(a[u].first == 0) continue;
        idx[++sl] = make_pair(a[u].second, u);

        --a[a[u].second].first;
        if(a[a[u].second].first == 1)
            unf.push(a[u].second);
        a[a[u].second].second ^= u;
    }

    printf("%d\n", sl);
    for(int i = 1; i <= sl; ++i){
        printf("%d %d\n", idx[i].first, idx[i].second);
    }
}