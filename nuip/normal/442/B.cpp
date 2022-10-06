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
typedef pair<double,double> pdd;

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k;
  int n;
  cin>>n;
  vector<pdd> v(n);
  rep(i,n){
    cin>>v[i].X;
    v[i].Y=1-v[i].X;
  }
  sort(rall(v));
  if(v[0].X>=0.5){
    cout<<v[0].X<<endl;
    return 0;
  }
  pdd re=pdd(0,1);
  rep(i,n){
    if(re.Y<re.X)
      break;
    pdd tmp;
    tmp.X=re.Y*v[i].X+re.X*v[i].Y;
    tmp.Y=re.Y*v[i].Y;
    if(re<tmp)
      re=tmp;
  }
  cout<<fixed<<setprecision(10)<<re.X<<endl;
  return 0;
}