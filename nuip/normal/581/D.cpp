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
#include<cassert>
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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  vv<int> ps(3,vector<int>(2));
  rep(i,3) cin>>ps[i][0]>>ps[i][1];
  int mx=0,area=0;
  for(auto &p:ps){
    if(p[0]<p[1]) swap(p[0],p[1]);
    mx=max(mx,p[0]);
    area+=p[0]*p[1];
  }
  if(mx*mx!=area){
    cout<<-1<<endl;
    return 0;
  }
  int cnt=0;
  for(auto &p:ps){
    cnt+=(p[0]==mx);
  }
  if(cnt==3){
    cout<<mx<<endl;
    char c='A';
    for(auto &p:ps){
      rep(i,p[1])
	cout<<string(mx,c)<<endl;
      ++c;
    }
  }else if(cnt==2){
    cout<<-1<<endl;
    //assert(0);
  }else{//cout<<"ok"<<endl;
    rep(i,3) ps[i].pb(i+'A');
    sort(all(ps));
    int rem=mx-ps[2][1];
    rep(i,2) if(ps[i][0]!=rem) swap(ps[i][0],ps[i][1]);
    rep(i,2) if(ps[i][0]!=rem){
      cout<<-1<<endl;
      return 0;
    }
    if(ps[0][1]+ps[1][1]!=mx){
      cout<<-1<<endl;
      return 0;
    }
    cout<<mx<<endl;
    rep(i,ps[2][1]) cout<<string(mx,ps[2][2])<<endl;
    rep(i,ps[0][0]) cout<<string(ps[0][1],ps[0][2])
			<<string(ps[1][1],ps[1][2])<<endl;
  }
  return 0;
}