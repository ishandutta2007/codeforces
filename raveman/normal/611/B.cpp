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

int main(){
#ifdef LocalHost
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
#endif

  ll a,b;
  cin>>a>>b;
  int res = 0;
  for (int len=2;len<=63;len++){
    for(int pos=1;pos<len;pos++){
      ll y = 0;
      for(int i=0;i<len;i++){
	if(i==pos) continue;
	y += 1ll<<(len-1-i);
      }
      if (y>=a && y<=b) res++;
    }
  }
  cout<<res<<endl; 

#ifdef LocalHost
  printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
  return 0;
}