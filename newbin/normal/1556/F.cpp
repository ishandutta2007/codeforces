#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
#define all(vec) vec.begin(),vec.end()
using namespace std;
int win[14][1<<14];
int n, a[15];
const int mod = 1e9 + 7;
int qm(int a, int b){int res = 1; for(;b;b>>=1,a=(ll)a*a%mod) if(b&1) res = (ll)res*a%mod; return res; }
int c[15][15];
int cc[1<<14];
int h[1<<14];
int main()
{
    h[1] = 0; for(int i = 1; i < 14; ++i) h[1<<i] = i;
    scanf("%d", &n);
    fors(i,0,n) cin>>a[i];
    fors(i,0,n) fors(j,0,n) c[i][j] = qm(a[i]+a[j], mod-2);
    fors(i,0,n){
        fors(mask,0,(1<<n)){
            int f=1;
            fors(j,0,n) if(mask>>j&1) f = (ll)f*a[i]%mod*c[i][j]%mod;
            win[i][mask] = f;
        }
    }
    int S = (1<<n)-1; int ans = 0;
    for(int mask = 1; mask < (1<<n); ++mask){
        cc[mask] = 1;
        for(int sub = mask&(mask-1); sub; sub = (sub-1)&mask){
            int res = mask^sub;
            int f = 1;
            int x = sub;
            while(x){
                int pos = h[lowbit(x)]; x -= lowbit(x);
                f = (ll)f*win[pos][res]%mod;
            }
            cc[mask] = (cc[mask] - (ll)f*cc[sub])%mod;
        }
        int x = mask;
        int cnt = 0;
        int f = 1;
        while(x){
            cnt++; int pos = h[lowbit(x)]; x -= lowbit(x);
            f = (ll)f*win[pos][S^mask]%mod;
        }
        ans = (ans + (ll)f*cc[mask]%mod*cnt%mod)%mod;
    }
    ans = (ans + mod)%mod;
    cout<<ans<<endl;
	return 0;
}
/*
3
1 1 1
*/