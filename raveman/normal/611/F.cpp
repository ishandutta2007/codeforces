#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b) memset(a,b,sizeof a)
#define pb push_back

const int mod = 1000000000+7;

int n,h,w;
string s;
ll res;

int l = 0;
int r = 0;
int u = 0;
int d = 0;

int x = 0, y = 0;
ll addd=0;

void doo(vector<pii>* interesting){
  interesting->clear();
  REP(i,n){
    if (l+r>=w || u+d>=h) break;
    if(s[i]=='R') y++;
    if(s[i]=='L') y--;
    if(s[i]=='U') x--;
    if(s[i]=='D') x++;
    if (-x > u){
      u++;
      res = (res + (w-l-r) * ll(i+1+addd)) %mod;
      interesting->pb(pii(i,1));
    }
    if (x > d) {
      d++;
      res = (res + (w-l-r) * ll(i+1+addd))% mod;
      interesting->pb(pii(i,2));
    }
    if (-y > l) {
      l++;
      res = (res + (h-u-d)*ll(i+1+addd))%mod;
      interesting->pb(pii(i,3));
    }
    if (y > r){
      r++;
      res = (res + (h-u-d)*ll(i+1+addd))%mod;
      interesting->pb(pii(i,4));
    }
    if (l+r==w || u+d==h) break;
  }
 }

void doo(vector<pii>& intersting){
  REP(i,intersting.size()){
    if (l+r>=w || u+d>=h) break;
    if (intersting[i].second==1) {
      u++;
      res = (res + (w-l-r) * ll(intersting[i].first+1+addd)) %mod;
    }
    if (intersting[i].second==2) {
      d++;
      res = (res + (w-l-r) * ll(intersting[i].first+1+addd))% mod;
    }
    if (intersting[i].second==3) {
      l++;
      res = (res + (h-u-d)*ll(intersting[i].first+1+addd))%mod;
    }
    if (intersting[i].second == 4){
      r++;
      res = (res + (h-u-d)*ll(intersting[i].first+1+addd))%mod;
    }
    if (l+r==w || u+d==h) break;
  }
}


ll stupid(){
  res=0;
  addd=0;
  u=d=r=l=0;x=y=0;
  vector<pii> tmp;
  REP(i,100){
    doo(&tmp);
    addd+=n;
  }
  if(u+d<h && l+r<w) return -1;
  return res;
}

int main(){
#ifdef LocalHost
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
#endif

  cin>>n>>h>>w;
  cin>>s;

  u=r=l=d=x=y=0;res=0;
  vector<pii> intersting;
  doo(&intersting);

  //cout<<res<<' '<<x<<' '<<y<<' '<<u<<' '<<d<<' '<<l<<' '<<r<<endl;

  ll extra = 0;

  if(x==0 && y==0 && l+r<w && u+d<h) res=-1;
  else if(l+r<w && u+d<h){
    int rh = h - u - d;
    int rw = w - l - r;

    int dx = x;
    int dy = y;
    ll tres = res;
    int adx = abs(dx);
    int ady = abs(dy);

    {
      ll trh = rh;
      ll trw = rw;
      while(trh>0 && trw>=0){
	extra = (extra +trh*trw%mod*n)% mod;
	trh -= adx;
	trw -= ady;
      }
    }

    intersting.clear();
    doo(&intersting);

    while (l+r<w && u+d<h){
      doo(intersting);
    }
  }
  ll ttres = res;
  cout<<(ttres+extra)%mod<<endl;

#ifdef LocalHost
  printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
  return 0;
}