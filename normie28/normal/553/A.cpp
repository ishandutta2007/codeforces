#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define itn int
#define pp pair<int,ll>
#define fi first
#define se second
#define sc(a) scanf("%d" , &a)
#define scl(a) scanf("%lld" , &a)
#define lg 18
#define all(v)        ((v).begin()), ((v).end())
#define sz(v)       ((int)((v).size()))
#define clr(v, d)     memset(v, d, sizeof(v))
#define fo(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define fod(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define foa(v)       fo(i, 0, sz(v)) fo(j, 0, sz(v[i]))
#define fov(i, v)     for(auto i:v)
#define lp(i, cnt)      fo(i, 0, cnt)
#define lpi(i, s, cnt)    fo(i, s, cnt)
#define P(x)        cout<<#x<<" = { "<<x<<" }\n"
#define pb          push_back
#define MP          make_pair
#define IOS  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test    int TEST;cin>>TEST;fo(T,1,TEST+1)
const ll MOD = 1000000007;
const int MAX = 1e9+7;
const int MIN = -1e9+7;
using namespace std;
 
 
ll power(int x ,int y){
 
	if(y==0)
	    return 1;
 
	ll ans = power(x,y/2)%MOD;
 
	ans = (ans * ans)%MOD;
 
	if(y&1) ans *=x%MOD , ans%=MOD ;
 
	return ans%MOD ;
}
 
 
ll inv(ll y){
 
return ( power(y%MOD,MOD-2))%MOD;
 
}
 
ll fact[5000000];
ll nCr(ll n ,ll r){
 
return (fact[n] * inv( (fact[r]*fact[n-r])%MOD ) )%MOD;
 
}
 
 
int main()
{
    IOS;
 
    fact[1005];
    fact[0]=1;
    fo(i,1,1001){
        fact[i] = (fact[i-1]*i)%MOD;
        fact[i]%= MOD;
    }
 
    int k;
    cin>>k;
 
    int c[k+5];
    ll sum[k+5] ;
    sum[0] = 0;
    fo(i,0,k){
        cin>>c[i];
        sum[i+1] = sum[i]+c[i];
        sum[i+1]%=MOD;
    }
 
    ll ans = 1;
    fo(i,0,k){
        ans *= nCr(sum[i+1]-1,c[i]-1)%MOD;
        ans%=MOD;
    }
    cout<<ans%MOD;
 
    return 0;
}