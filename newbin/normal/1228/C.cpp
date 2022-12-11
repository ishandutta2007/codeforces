#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const ll mod = 1e9 + 7;
ll qm(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res * a%mod;
        a = a*a%mod; b>>=1;
    }return res;
}
int p[100];
int cnt = 0;
int main()
{
    int x; ll n; cin>>x>>n;
    for(int i = 2; i*i <= x; ++i){
        if(x%i == 0){
            p[cnt++] = i;
            while(x%i == 0) x/=i;
        }
    }
    if(x != 1) p[cnt++] = x;
    ll ans = 1;
    for(int i = 0; i < cnt; ++i){
        ll t = p[i];
        while(t <= n){
            ans = ans * qm(p[i], n/t)%mod;
            if(t <= n/p[i]) t = t*p[i];
            else break;
        }
    }cout<<ans<<endl;
}