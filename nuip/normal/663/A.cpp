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
  int p=1,n=0;
  string str;
  vector<int> isp;
  while(1){
    cin>>str>>str;
    if(str=="=") break;
    isp.pb(str=="+");
    if(str=="+") ++p;
    if(str=="-") ++n;
  }
  int m;
  cin>>m;
  int sum=p-n*m;
  //cout<<sum<<","<<p<<","<<n<<endl;
  if(sum>m || sum+(m-1ll)*(p+n)<m){
    cout<<"Impossible"<<endl;
    return 0;
  }
  int rem=m-sum;
  vector<int> ps;
  rep(i,p){
    int x=min(rem,m-1);
    rem-=x;
    ps.pb(x+1);
  }
  vector<int> ns;
  rep(i,n){
    int x=min(rem,m-1);
    rem-=x;
    ns.pb(m-x);
  }
  //cout<<isp<<ps<<ns;
  cout<<"Possible"<<endl;
  cout<<ps.back(); ps.pop_back();
  for(int a:isp){
    if(a){
      cout<<" + "<<ps.back();
      ps.pop_back();
    }else{
      cout<<" - "<<ns.back();
      ns.pop_back();
    }
  }
  cout<<" = "<<m<<endl;
  return 0;
}