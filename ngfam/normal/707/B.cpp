#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(false); cout.tie(false);
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const int N = 1e6 + 1, mod = 1e9 + 7;

struct edge{
    int u;
    int v;
    int l;
}a[N];

bool done[N];
int n, m, k, x, rs = mod;

void MAIN(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i) cin >> a[i].u >> a[i].v >> a[i].l;
    for(int i = 1; i <= k; ++i){
         cin >> x;
         done[x] = 1;
    }
    
    for(int i = 1; i <= m; ++i){
        if(done[a[i].u] && !done[a[i].v]) rs = min(rs, a[i].l);
        if(!done[a[i].u] && done[a[i].v]) rs = min(rs, a[i].l);
    }
    cout << (rs == mod ? -1 : rs);
}