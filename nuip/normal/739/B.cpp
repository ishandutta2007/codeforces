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

priority_queue<int> que;
vector<ll> a;
void dfs(vv<pll> &g,int v,vector<int> &re,ll dep){
  for(pll p:g[v]) dfs(g,p.X,re,dep+p.Y);
  while(que.size() && que.top()>dep) que.pop();
  re[v]=que.size();
  que.push(dep-a[v]);
}

void dfs(vv<pll> &g,int v,vector<ll> &re,ll dep,vector<int> &l,vector<int> &r,int &cnt){
  re[v]=dep;
  l[v]=cnt++;
  for(pll p:g[v]) dfs(g,p.X,re,dep+p.Y,l,r,cnt);
  r[v]=cnt;
}

const int nn=212345;
ll bit[nn+1];

ll sum(int i){ ++i;
  ll s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(int i,ll x){ ++i;
  while(i<=nn){
    bit[i]+=x;
    i+=i&-i;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  a.resize(n);
  rep(i,n) cin>>a[i];
  vv<pll> g(n);
  rep(i,n-1){
    int x,y;
    cin>>x>>y; --x;
    g[x].eb(i+1,y);
  }
  vector<ll> dep(n);
  vector<int> l(n),r(n);
  int cnt=0;
  dfs(g,0,dep,0,l,r,cnt);
  //cout<<dep<<l<<r;
  vector<pll> qs(n);
  rep(i,n) qs[i]=pll(dep[i],i);
  sort(rall(qs));
  vector<pll> wei(n);
  rep(i,n) wei[i]=pll(dep[i]-a[i],l[i]);
  sort(all(wei));
  vector<int> re(n);
  for(pll q:qs){
    while(wei.size() && wei.back().X>q.X){
      add(wei.back().Y+1,1);
      //cout<<"add: "<<wei.back().Y<<endl;
      wei.pop_back();
    }
    //cout<<q<<pii(l[q.Y],r[q.Y])<<endl;
    re[q.Y]=sum(r[q.Y])-sum(l[q.Y]);
  }
  //cout<<re;
  rep(i,n) cout<<r[i]-l[i]-re[i]-1<<" ";cout<<endl;
  return 0;
}