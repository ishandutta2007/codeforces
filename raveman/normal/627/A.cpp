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

map<pair<ll,ll>, ll> r;
ll go(ll s,ll x){
  if(s<0)return 0;
  if(s==0){
    return x==0?1:0;
  }
  if(r.count(make_pair(s,x))) return r[make_pair(s,x)];
  ll num = 0;
  REP(i,2)REP(j,2)if((i+j)%2==s%2)if((i^j)==x%2){
      num += go((s-i-j)/2,x/2);
  }
  return r[make_pair(s,x)]=num;
}


int main(){
  ll s,x;
  cin>>s>>x;
  ll res = go(s,x);
  if(s==x)res-=2;
  cout<<res<<endl;
  return 0;
}