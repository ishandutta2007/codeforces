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
#include<iomanip>
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
  int i,j,k;
  ll n,t;
  cin>>n>>t;
  if(n==1){
    cout<<0<<endl;
  }else if(n<=t){
    cout<<1<<endl;
  }else if(1+(t-1)*t/2<n){
    cout<<-1<<endl;
  }else{
    ll m,l=0,r=t;
    while(r-l>1){
      m=(l+r)/2;
      //   cout<<l<<","<<r<<":"<<(t+t-m+1)*m/2+1<<endl;
      if( (t+t-m-1)*m/2+1 < n )
	l=m;
      else
	r=m;
    }
    cout<<r<<endl;
  }
  return 0;
}