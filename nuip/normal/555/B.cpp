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
const ll INF=1e18+10;
typedef pair<pll,ll> plll;
int main(){
  //ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  scanf("%d%d",&n,&m);
  vector<pll> inter(n-1);
  ll pl,pr,cl,cr;
  scanf("%I64d%I64d",&pl,&pr);
  rep(i,n-1){
    scanf("%I64d%I64d",&cl,&cr);
    inter[i]=pll(cl-pr,cr-pl);
    pl=cl; pr=cr;
  }
  vector<plll> srt(n);
  vector<pll> b(m);
  rep(i,n-1)
    srt[i]=plll(inter[i],(ll)i);
  srt[n-1]=plll(pll(INF,INF),-1);
  //cout<<inter<<srt;
  sort(rall(srt));
  
  rep(i,m){
    scanf("%I64d",&b[i].X);
    b[i].Y=i;
  }
  sort(all(b));
  //cout<<b;

  priority_queue<pll> que;
  vector<int> re(n-1);
  int f=1;
  //cout<<srt;
  rep(i,m){
    while(srt.back().X.X<=b[i].X){
      int i=srt.back().Y;
      //cout<<i<<endl;
      que.emplace(-inter[i].Y,i);
      srt.pop_back();
    }
    //cout<<que.size()<<endl;
    //cout<<srt;
    if(que.empty()) continue;
    pll t=que.top(); que.pop();
    //cout<<t<<","<<b[i]<<que.top()<<endl;
    if(-t.X<b[i].X){
      f=0; break;
    }
    re[t.Y]=b[i].Y;
  }
  if(!que.empty() || srt.back().X.X!=INF) f=0;
  if(f){
    printf("Yes\n");
    rep(i,n-1)
      printf("%d ",1+re[i]);
    printf("\n");
  }else{
    printf("No\n");
  }
  return 0;
}