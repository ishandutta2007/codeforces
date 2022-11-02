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
typedef pair<int,int>pii;
typedef pair<ld,ld>pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)for(int i=(a);i<(b);i++)
#define REP(i,n)FOR(i,0,n)
#define SORT(v)sort((v).begin(),(v).end())
#define UN(v)SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)memset(a,b,sizeof a)
#define pbpush_back

int d,n,m;
pii p[222222];

int main(){
  cin>>d>>n>>m;
  REP(i,m)scanf("%d %d",&p[i].first,&p[i].second);
  p[m] = pii(d,0);
  m++;
  p[m+1]=pii(0,0);
  m++;
  sort(p,p+m);

  set<pii> s;
  int p1=0,p2=0;
  ll pos = 0;
  ll res = 0;
  while(1){
    while(p2<m && pos + n >= p[p2].first) {
      s.insert(pii(p[p2].second, p2));
      ++p2;
    }
    while(p1<m && p[p1].first<=pos){
      s.erase(pii(p[p1].second, p1));
      ++p1;
    }
    if (p2>=m) break;
    if(s.empty()) {
      puts("-1");
      return 0;
    }
    pii x = *s.begin();
    ll amount = p[x.second].first - pos;
    amount = min(amount, (ll)p[p2].first - (pos+n));
    res += amount * ll(x.first);
    pos += amount;
  }
  cout<<res<<endl;
  
  return 0;
}