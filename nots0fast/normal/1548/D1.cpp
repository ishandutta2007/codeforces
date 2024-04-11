#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define pb(a) push_back(a)
#define ld long double
#define vi vector<int>
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,9);
ll modulo = pow(10,9)+7;
ld eps = 1e-13;

 
void deal(){
      ll n;
      cin>>n;
      vector<pair<ll,ll> > a(n);
      fori(n){
            cin>>a[i].ff>>a[i].ss;
            a[i].ff/=2, a[i].ss/=2;
            a[i].ff = (a[i].ff % 2);
            a[i].ss = (a[i].ss % 2);
      }
      vector<vector<ll> > dp(2, vector<ll>(2, 0));
      ll ans = 0;
      fori(n){
            for(ll j = i+1; j<n; j++){
                  ll s = a[i].ff * a[j].ss + a[j].ff * a[i].ss; 
                  fork(2){
                        forl(2){
                              ll cs = (s + a[j].ff * l + k * a[j].ss + k * a[i].ss + l * a[i].ff);
                              if(cs % 2 == 0){
                                    ans += dp[k][l];
                              }
                        }
                  }
            }
            dp[a[i].ff][a[i].ss]++;
      }
      cout<<ans;
}
 
 
int main(){
 	cin.tie(0);
 	ios_base::sync_with_stdio(0);
	deal();
}