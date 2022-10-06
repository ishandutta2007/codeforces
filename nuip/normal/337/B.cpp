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
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >


using namespace std;
typedef __int64 ll;

ll gcd(ll n,ll m){
  if(n<m)swap(n,m);

  if(m==0)return n;
  return gcd(m,n%m);
}

ll a,b,c,d,p,q;

ll check(ll s,ll t,ll u,ll v){//s:tu:v
  t*=u;
  v*=s;
  if(v<=t){
    p=t-v;
    q=t;
    ll tmp=gcd(p,q);
    p/=tmp;
    q/=tmp;
  }
  return 0;
}

int main(){
  cin>>a>>b>>c>>d;
  
  check(a,b,c,d);
  check(b,a,d,c);
  printf("%I64d/%I64d\n",p,q);
  return 0;
}