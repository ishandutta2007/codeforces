#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));


const ll mod=998244353;
const int N=600010;
const int L=20;
ll binpow(ll a,ll b){
    ll res=1ll;
    while (b){
        if (b&1) res=(res*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return res;
}
ll f[N];
ll rf[N];
ll C(int n,int k){
    if (k>n || k<0) return 0;
    return f[n]*rf[k]%mod*rf[n-k]%mod;
}
ll ans[N];
ll sum[N];
ll precalc[N];
ll pref[N];
int n,k;
int CNT=0;
ll val[N][L];
ll pw[N];
int D[N];
int M[N];
ll F(int x){
    if (precalc[x]) return precalc[x];
    CNT++;
    ll res=0ll;
    int k1=min(k,x);
    for (int j=1;j<=k1;j++){
        if (D[j]==j) pw[j]=binpow(j,x);
        else pw[j]=(pw[D[j]]*pw[j/D[j]])%mod;

        ll mult=rf[j]*pw[j]%mod;
        ll add=pref[k1-j];
        res+=add*mult;
        res%=mod;
    }




    return precalc[x]=res;
}
void solve(){
    cin>>n>>k;

    ll add=0ll;
    pref[0]=0;
    for (int i=0;i<=k;i++){
        if (i%2) add+=(mod-rf[i]);
        else add+=rf[i];
        add%=mod;
        pref[i]=add;
    }

    ll sum=0ll;
    ll res=0ll;
    for (int g=1;g<=n;g++){
        if (M[g]){
            res+=mod+M[g]*(F((n+g-1)/g)-1ll);
            res%=mod;

        }
    }

    if (n==1 || k==1) res=1;
    cout<<res<<endl;

}
int32_t main()
{
    for (int i=1;i<N;i++) D[i]=i;
    M[1]=1;
    for (int i=2;i<N;i++){
        if (D[i]==i){
            for (int j=i*2;j<N;j+=i) D[j]=i;
        }
        int x=i;
        int cnt=0;
        while (x%D[i]==0){
            x/=D[i];
            cnt++;
        }
        if (cnt>=2) M[i]=0;
        else M[i]=-M[i/D[i]];
    }
    f[0]=1;
    for (ll i=1;i<N;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    rf[N-1]=binpow(f[N-1],mod-2);
    for (ll i=N-1;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

//2
//
//1 2

/**
12837720
**/