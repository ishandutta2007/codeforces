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

int dx[4],dy[4],x[4],y[4],INF=100;
int cs[]={1,0,-1,0},sn[]={0,1,0,-1};
vector<pii> p(4);

int isSq(vector<pii> p){
  set<ll> d;
  rep(i,4)
    for(int j=i+1;j<4;j++){
      ll dxx=p[j].X-p[i].X,dyy=p[j].Y-p[i].Y;
      d.insert(dxx*dxx+dyy*dyy);
    }
  if(d.size()!=2)
    return 1;
  return (*d.begin())*2!= *(++d.begin());
}

int solve(int dep){
  if(dep==4){
    return isSq(p)*100;
  }
  int re=100;
  rep(i,4){
    p[dep].X=x[dep]+dx[dep]*cs[i]-dy[dep]*sn[i];
    p[dep].Y=y[dep]+dx[dep]*sn[i]+dy[dep]*cs[i];
    re=min(re,solve(dep+1)+i);
  }
  return re;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k,n,a,b;
  cin>>n;
  rep(i,n){
    rep(j,4){
      cin>>a>>b>>x[j]>>y[j];
      dx[j]=a-x[j];
      dy[j]=b-y[j];
    }
    int res=solve(0);
    cout<<(res==100?-1:res)<<endl;
  }
  return 0;
}