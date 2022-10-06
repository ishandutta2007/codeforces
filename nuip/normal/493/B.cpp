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
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,v,f;
  cin>>n;
  vector<int> a,b;
  rep(i,n){
    cin>>v;
    if(v>0){
      a.pb(v);
      f=1;
    }else{
      b.pb(-v);
      f=0;
    }
  }
  ll temp=accumulate(all(a),0ll)-accumulate(all(b),0ll);
  if(temp==0){
    if(a>b)
      f=1;
    if(a<b)
      f=0;
  }else if(temp>0)
    f=1;
  else if(temp<0)
    f=0;
  cout<<(f?"first":"second")<<endl;
  return 0;
}