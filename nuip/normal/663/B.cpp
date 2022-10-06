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
  //ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int T;
  cin>>T;
  vector<ll> hoge={0};
  vector<ll> ten={1};
  rep(i,9) hoge.pb(hoge.back()*10+1);
  rep(i,9) ten.pb(ten.back()*10);
  while(T--){
    string str;
    cin>>str;
    str=str.substr(4);
    stringstream ss;
    ss<<str;
    ll n;
    ss>>n;
    if(str.size()>=4){
      ll x=hoge[str.size()-4]*10000+3099;
      (n+=ten[str.size()]-x)%=ten[str.size()];
      cout<<x+n<<endl;
    }else if(str.size()==3){
      (n+=1000-99)%=1000;
      cout<<2099+n<<endl;
    }else if(str.size()==2){
      (n+=100-99)%=100;
      cout<<1999+n<<endl;
    }else{
      (n+=10-9)%=10;
      cout<<1989+n<<endl;
    }
  }
  return 0;
}