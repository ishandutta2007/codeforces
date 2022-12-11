#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

#define y0 PINGO
#define y1 CONCHA

int n;
ll x[300005],y[300005];
pair<ll,int> x0,x1,y0,y1;

ll do3(){
  set<int> w;
  w.insert(x0.second);
  w.insert(x1.second);
  w.insert(y0.second);
  w.insert(y1.second);
  if(SZ(w)<4)return x1.first-x0.first+y1.first-y0.first;
  vi v(w.begin(),w.end());
  ll r=0;
  FORN(ii,4)FOR(jj,ii+1,4){
    int i=v[ii],j=v[jj];
    FORN(k,n){
      if(k==i||k==j)continue;
      r=max(r,
        max({x[i],x[j],x[k]})-min({x[i],x[j],x[k]})+
        max({y[i],y[j],y[k]})-min({y[i],y[j],y[k]})
      );
    }
  }
  return r;
}

int main(){
  x0=make_pair(1<<30,-1);y0=make_pair(1<<30,-1);
  x1=make_pair(-(1<<30),-1);y1=make_pair(-(1<<30),-1);
  scanf("%d",&n);
  FORN(i,n){
    scanf("%lld%lld",x+i,y+i);
    x0=min(x0,make_pair(x[i],i));
    x1=max(x1,make_pair(x[i],i));
    y0=min(y0,make_pair(y[i],i));
    y1=max(y1,make_pair(y[i],i));
  }
  printf("%lld",2*do3());
  ll r=x1.first-x0.first+y1.first-y0.first;
  FOR(i,4,n+1)printf(" %lld",2*r);
  puts("");
  return 0;
}