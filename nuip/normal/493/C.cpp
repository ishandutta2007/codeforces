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
  int n,m,v;
  map<int,pii> sum;
  cin>>n;
  rep(i,n){
    cin>>v;
    ++(sum[v].X);
  }
  cin>>m;
  rep(i,m){
    cin>>v;
    ++(sum[v].Y);
  }
  int x,y,mx=(n-m)*3,x2,y2;
  x=y=x2=y2=0;
  for(auto p:sum){
    x+=p.Y.X;
    y+=p.Y.Y;
    int tmp=(n-x)*3+x*2-(m-y)*3-y*2;
    if(tmp>mx){
      mx=tmp;
      x2=x;
      y2=y;
    }
  }
  cout<<(n-x2)*3+x2*2<<":"<<(m-y2)*3+y2*2<<endl;
  return 0;
}