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
 
  int a;
  string b,c;
  cin>>a>>b>>c;
  int res = 0;
  if (c=="month") {
    if (a<=29) res = 12;
    if (a==30) res = 11;
    if (a==31) res = 7;
  }else{
    res = 52;
    if (a == 5 || a==6) res = 53;
  }
  cout<<res<<endl;

#ifdef LocalHost
  printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
  return 0;
}