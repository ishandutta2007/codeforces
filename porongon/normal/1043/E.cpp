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

int n,m;
vector<pair<ll,int> > w;
ll x[300005],y[300005];
ll sx[300005],sy[300005];
ll r[300005];

int main(){
  scanf("%d%d",&n,&m);
  FORN(i,n){
    scanf("%lld%lld",x+i,y+i);
    w.push_back(make_pair(x[i]-y[i],i));
  }
  sort(w.begin(),w.end());
  reverse(w.begin(),w.end());
  FORN(i,n){
    sx[i+1]=sx[i]+x[w[i].second];
    sy[i+1]=sy[i]+y[w[i].second];
  }
  FORN(i,n){
    int k=w[i].second;
    r[k]=i*x[k]+sy[i]+(n-1-i)*y[k]+sx[n]-sx[i+1];
  }
  while(m--){
    int i,j;
    scanf("%d%d",&i,&j);i--;j--;
    ll a=min(x[i]+y[j],x[j]+y[i]);
    r[i]-=a;r[j]-=a;
  }
  FORN(i,n)printf("%lld%c",r[i]," \n"[i==n-1]);
  return 0;
}