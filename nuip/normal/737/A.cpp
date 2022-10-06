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
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  ll n,m,s,t;
  cin>>n>>m>>s>>t;
  vector<pii> ps(n);
  rep(i,n) cin>>ps[i].X>>ps[i].Y;
  vector<int> g(m);
  rep(i,m) cin>>g[i];
  g.pb(0); g.pb(s);
  sort(all(g));
  vector<int> len(m+1);
  rep(i,m+1) len[i]=g[i+1]-g[i];
  sort(all(len));
  sort(all(ps));
  vector<ll> sum(m+2);
  rep(i,m+1) sum[i+1]=sum[i]+len[i];
  //cout<<len<<sum<<ps;
  for(pii p:ps){
    ll c=p.Y;
    if(c<len.back()) continue;
    int l=upper_bound(all(len),c/2)-len.begin();
    int r=upper_bound(all(len),c)-len.begin();
    ll red=0;
    red+=sum[l]*2;
    red+=1ll*c*(r-l)-sum[r];
    //cout<<pii(l,r)<<red<<endl;
    if(s*2-red<=t){
      cout<<p.X<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}