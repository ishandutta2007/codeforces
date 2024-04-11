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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
const ll MOD=1e9+7;
const ll INF=1e8;
typedef pair<ll,pll> plll;
typedef pair<string,int> psi;
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  string s,t;
  cin>>s>>t;
  int n=s.size(),m=t.size();
  rep(i,m) if(s.find(t[i])==string::npos){
    cout<<-1<<endl;
    return 0;
  }
  vector<psi> strs(2*n);
  rep(j,2){
    rep(i,n)strs[j*n+i]=psi(s.substr(i),j*n+i);
    reverse(all(s));
  }
  strs.eb("!",-1); strs.eb("|",-1);
  sort(all(strs));
  
  vector<plll> dp(m+1,plll(INF,pll(-1,-1)));
  dp[m].X=0;
  rrep(i,m){
    auto it=lower_bound(all(strs),psi(t.substr(i),-INF));
    auto ite=it; --ite;
    int l=0,r=0;
    for(;(ite->X)[l]==t[i+l];++l) ;
    for(;(it->X)[r]==t[i+r];++r) ;
    psi use= l<r? *it : *ite;
    //cout<<i<<use<<l<<","<<r<<endl;
    rep(j,max(l,r)){
      if(i+j+1>m) break;
      plll tmp=dp[i+j+1];
      ++tmp.X; tmp.Y.X=i+j+1; tmp.Y.Y=use.Y;
      dp[i]=min(dp[i],tmp);
    }
  }
  // cout<<strs<<dp;

  cout<<dp[0].X<<endl;
  for(int cur=0; cur<m; cur=dp[cur].Y.X){
    if(cur<0) for(;;);
    plll tmp=dp[cur];
    if(tmp.Y.Y<n){
      cout<<tmp.Y.Y+1<<" "<<tmp.Y.Y+tmp.Y.X-cur<<endl;
    }else{
      cout<<n-(tmp.Y.Y-n)<<" "<<n-(tmp.Y.Y-n+tmp.Y.X-cur-1)<<endl;
    }
  }
  
  return 0;
}