#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define db(x) cout << "==========>> " << #x << " is " << x << endl
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i,j) FOR(i,0,j,1)
#define RREP(i,j) RFOR(i,j,0,1)
#define INF (int)1e9
#define EPS 1e-9
#define MOD 998244353
#define all(cont) cont.begin(), cont.end()
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP make_pair
#define PB push_back
using namespace std;
ll N,total,arr,total2,BIT[1000005];
string s;
ll ppow(ll n, ll x){
    if (x==1){
        return n%MOD;
    }
    if (x==0){
        return 1;
    }
    ll k=1;
    if (x&1){
        k=n;
    }
    ll k2=ppow(n, x/2)%MOD;
    ll k3= ((k2%MOD)*(k2%MOD))%MOD;
    k3= ((k3%MOD)*(k%MOD))%MOD;
    k3%=MOD;
    return k3;
}
int main (){
    ll a,b;
    cin>>a>>b;
    ll k=ppow(2, a+b);
    cout << k << endl;
}