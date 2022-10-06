#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstring>
#include<sstream>
#include<complex>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<ll> buildFail(vector<ll> p) {
  ll m = p.size();
 //   cerr<<",";
  //p.pb(1e9+10);
  vector<ll> fail(m+1);
//    cerr<<",";
  ll j = fail[0] = -1;
//    cerr<<m<<",!";
  for (ll i = 1; i <= m; ++i){
 //   printf("%d,",i);fflush(stdout);
    while ( j >= 0 && p[j] != p[i-1]) j = fail[j];
    fail[i] = ++j;
  }
  return fail;
}

ll match(vector<ll> t, vector<ll> p,vector<ll> fail) {
  ll n = t.size(), m = p.size();
//  t.pb(1e9+10),p.pb(1e9+10);
  ll count = 0;
  for (ll i = 0, k = 0; i < n; ++i) {
    while (m > k && k >= 0 && p[k] != t[i]) k = fail[k];
    if (++k >= m) {
      ++count; // match at t[i-m+1 .. i]
      k = fail[k];
    }
  }
  return count;
}
int main(){
  ll i,j,k;
  ll n,m;
  cin>>n>>m;
  if(n<m){
    cout<<0<<endl;
    return 0;
  }
  if(m==1){
    cout<<n<<endl;
    return 0;
  }
  vector<ll> a(n+100),b(m+100),ad(n-1),bd(m-1);
  ll hashb=0,r=173205080,hasha=0,MOD=1e9+7;
  rep(i,n)
    cin>>a[i];
  rep(i,n-1)
    ad[i]=a[i+1]-a[i]+1e9;
  rep(i,m)
    cin>>b[i];
  rep(i,m-1){
    bd[i]=b[i+1]-b[i]+1e9;
    hashb*=r;
    hashb=(hashb%MOD+MOD)%MOD;
    hashb+=bd[i];
    hashb=(hashb%MOD+MOD)%MOD;
  }
 /* rep(i,n-1)
    cout<<ad[i]<<",";cout<<endl;
  rep(i,m-1)
    cout<<bd[i]<<",";cout<<endl;*/
  vector<ll> fail=buildFail(bd);
  cout<<match(ad,bd,fail)<<endl;
  /*ll rr=1;
  rep(i,m-1){
    rr*=r;
    rr%=MOD;
    hasha*=r;
    hasha=(hasha%MOD+MOD)%MOD;
    hasha+=ad[i];
    hasha=(hasha%MOD+MOD)%MOD;
  }
//  cout<<hasha<<","<<hashb<<endl;
  ll re=0;
  for(i=m-1;i<n;i++){
    if(hasha==hashb)
      re++;
    if(i==n-1)break;
    hasha*=r;
    hasha=(hasha%MOD+MOD)%MOD;
    hasha-=ad[i-m+1]*rr;
    hasha+=ad[i];
    hasha=(hasha%MOD+MOD)%MOD;
  }
  cout<<re<<endl;*/
  return 0;
}