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
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
  std::ios_base::sync_with_stdio(false);
  int n,i,j,k;
  ll l,r,re,re2;
  cin>>n;
//  cout<<RAND_MAX<<endl;
  while(n--){
    cin>>l>>r;
//    l=1ll*rand()*rand()*rand()*rand()%ll(1e18);
//    r=1ll*rand()*rand()*rand()*rand()%ll(1e18);
    if(r<l)
      swap(l,r);
    if((r^(r+1)) == 0){
      cout<<r<<endl;
      continue;
    }
    re=l;
    rep(i,63){
      if((re>>i)&1)
        continue;
      if((re|(1ll<<i)) <= r)
        re|=1ll<<i;
    }
    if(re<l || r<re)
      re=l;
    re2=0;
    rrep(i,63){
      if( (l&(1ll<<i)) == (r&(1ll<<i)) ){
//        cout<<i<<",";
        re2+=(l&(1ll<<i));
      }else{
        re2+=(1ll<<i)-1;
        if(re2+(1ll<<i)<=r)
          re2+=1ll<<i;
        break;
      }
    }
    if(re2<l || r<re2)
      re2=l;
  //  cout<<re<<","<<re2<<endl;
    int a=__builtin_popcount(re),b=__builtin_popcount(re2);
    if(re!=re2&&0){
      cout<<l<<","<<r<<"->"<<re<<","<<re2<<endl;
      cout<<a<<","<<b<<endl;
    }
    if(a==b){
      cout<<min(re,re2)<<endl;
    }else if(a>b){
      cout<<re<<endl;
    }else{
      cout<<re2<<endl;
    }
  }
  return 0;
}