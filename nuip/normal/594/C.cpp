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
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
const ll MOD=1e9+7;
#include<cassert>
int memo[112345];
int main(){
  //ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,tt;
  scanf("%d%d",&n,&tt);
  vector<pii> vs[4];
  rep(i,n){
    ll x,y,X,Y;
    scanf("%I64d%I64d%I64d%I64d",&x,&y,&X,&Y);
    vs[0].eb(X+x,i);
    vs[2].eb(Y+y,i);
  }
  vs[1]=vs[0];
  vs[3]=vs[2];
  sort(all(vs[0]));
  sort(rall(vs[1]));
  sort(all(vs[2]));
  sort(rall(vs[3])); 
  ll re=1ll*max(2ll,vs[1][0].X-vs[0][0].X+1)/2*
	   (max(2ll,vs[3][0].X-vs[2][0].X+1)/2);
  int t=tt;
  fill(memo,memo+112345,-1);
  rep(i,1<<(t*2)){
    int ind[4]={};
    rep(j,t){
      int k=i>>(2*j)&3;
      while(memo[vs[k][ind[k]].Y]==i) ++ind[k];
      memo[vs[k][ind[k]++].Y]=i;
    }
    rep(k,4)
      while(memo[vs[k][ind[k]].Y]==i) ++ind[k];
    //rep(k,4)cout<<ind[k]<<";";cout<<endl;
    //for(int k:st)cout<<k<<",";cout<<endl;
    re=min(re,1ll*max(2ll,vs[1][ind[1]].X-vs[0][ind[0]].X+1)/2*
	   (max(2ll,vs[3][ind[3]].X-vs[2][ind[2]].X+1)/2));
    //rep(k,4)cout<<vs[k][ind[k]]<<";";cout<<endl;
    //assert(ind[1]+ind[0]<n-1 && ind[2]+ind[3]<n-1);
  }
  printf("%I64d\n",re);
  return 0;
}