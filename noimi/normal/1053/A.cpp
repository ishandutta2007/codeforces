#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 1000010
#define MAX_V 900010
using namespace std;
ll int inv[N],comb[N],prd[N],invprd[N];
void calc_inv(){
    inv[1]=1;
    rep2(i,2,N){
        inv[i]=((-(MOD/i)*inv[MOD%i])%MOD+MOD)%MOD;
    }
    return;
}
void calc_comb(ll int n){
    comb[0]=1;
    rep2(i,1,n){
        comb[i]=comb[i-1]*(n+1-i)*inv[i]%MOD;
    }
    return;
}
void calc_product(){
    prd[0]=prd[1]=1;
    invprd[0]=invprd[1]=1;
    rep2(i,2,N){
        prd[i]=i*prd[i-1]%MOD;
        invprd[i]=inv[i]*invprd[i-1]%MOD;
    }
    return ;
}
ll cmb(int a,int b){
    return prd[a]*invprd[b]%MOD*invprd[a-b]%MOD;
}
ll modpow(ll x,ll n){
    if(n==0) return 1;
    ll res=modpow(x*x%MOD,n/2);
    if(n&1) res=res*x%MOD;
    return res;
}
gcd(ll a,ll b){
    return (a?gcd(b%a,a):b);
}
main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll g=gcd(n*m,k);
    ll t=n*m/g,s=k/g;
    if(s>2){
        cout<<"NO";
        return 0;
    }
    t=(s==1?t*2:t);
    if(t>n*m){
        cout<<"NO";return 0;
    }
    cout<<"YES"<<endl;
    cout<<0<<" "<<0<<endl;
    cout<<n<<" "<<1<<endl;
    cout<<n*((t+n-1)/n)-t<<" "<<((t+n-1)/n);
}