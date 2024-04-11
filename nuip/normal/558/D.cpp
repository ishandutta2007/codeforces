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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int h,q;
  cin>>h>>q;
  int dep,ans;
  ll l,r;
  map<ll,ll> sum;
  sum[1<<(h-1)]=sum[1<<h]=0;
  rep(i,q){
    cin>>dep>>l>>r>>ans; ++r;
    l<<=h-dep; r<<=h-dep;
    if(ans){
      ++sum[l]; --sum[r];
    }else{
      ++sum[1ll<<(h-1)]; --sum[l];
      ++sum[r]; --sum[1ll<<(h)];
    }
  }
  pll pre=pll(1<<(h-1),0);
  ll re=-1;
  ll len=0;
  //for(const pll &p:sum)cout<<p;cout<<endl;
  
  for(const pll &p:sum){
    if(pre.Y == q){
      len+=(p.X-pre.X);
      re=pre.X;
    }
    pre.X=p.X;
    pre.Y+=p.Y;
  }
  //cout<<len<<endl;
    if(!len){
	cout<<"Game cheated!"<<endl;
    }else if(len>1){
	cout<<"Data not sufficient!"<<endl;
    }else{
      cout<<re<<endl;
    }
  return 0;
}