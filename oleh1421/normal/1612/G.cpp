//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=2000000;
const ll mod=1000000007ll;
int cnt[N*2+5];
ll f[N*2+5];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        int c;cin>>c;
        cnt[-c+1+N]++;
        cnt[c+1+N]--;
    }
    for (int i=2;i<=N*2;i++) cnt[i]+=cnt[i-2];
    f[0]=1ll;
    for (ll i=1;i<=N*2;i++) f[i]=(f[i-1]*i)%mod;
    ll sum=0ll;
    ll val=0ll;
    ll res=1ll;
    for (int i=0;i<=N*2;i++){
        val+=(sum*2ll+cnt[i]+1ll)%mod*(cnt[i]*1ll)%mod*(i-N+0ll)%mod*((mod+1)/2ll)%mod;
        val%=mod;
        sum+=cnt[i];
        res*=f[cnt[i]];
        res%=mod;
    }
    cout<<val<<" "<<res<<endl;

}
int32_t  main()
{
//    cin>>X>>Y;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}

/**
11 3
1 2
2 3
3 4
4 5
5 6
6 7
4 8
8 9
9 10
10 11
**/