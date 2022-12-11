#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 1e6 + 5;
int k;
ll dp[maxn];
const ll inf = 0x3f3f3f3f3f3f3f3f;
int main()
{
    fors(i,0,maxn) dp[i] = -inf;
    dp[0] = 0;
    scanf("%d", &k);
    ll f[6], pw[6]; fors(i,0,6) cin>>f[i];
    pw[0] = 1; fors(i,1,6) pw[i] = pw[i-1]*10;
    fors(i,0,6){
        ll t = 3*(k-1);
        for(int j = 0; j < 20 && t; ++j) {
            ll w, v;
            if(t >= (1<<j)) t -= (1<<j), w = (1<<j)*3*pw[i], v = (1<<j)*f[i];
            else w = t*3*pw[i], v = t*f[i], t = 0;
            for(int k = maxn-1; k >= w; --k) dp[k] = max(dp[k], dp[k-w] + v);
        }
    }
    fors(i,0,6){
        ll v[10]; memset(v,0,sizeof v); fors(j,1,4) v[j*3] = j*f[i];
        for(int k = maxn-1; k >= 0; --k){
            for(int j = 1; j < 10; ++j) if(k >= j*pw[i])dp[k] = max(dp[k], dp[k-pw[i]*j] +  v[j]);
        }
    }
    int q, n; cin>>q;
    while(q--) scanf("%d", &n), printf("%lld\n", dp[n]);
	return 0;
}