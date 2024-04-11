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
  string s;
  cin>>s;
  vv<int> cnt(200);
  rep(i,27) cnt[s[i]].pb(i);
  char c;
  rep(i,200) if(cnt[i].size()==2) c=i;
  if(cnt[c][0]==cnt[c][1]-1){
    cout<< "Impossible"<<endl;
    return 0;
  }
  string a=s.substr(0,cnt[c][0]);
  string b=s.substr(cnt[c][1]+1);
  reverse(all(b));
  if(a.size()<b.size()) swap(a,b);
  reverse(all(b));
  int t=(a.size()-b.size()+1)/2;
  string re1=a.substr(t);
  string re2=b+a.substr(0,t);
  string rem=s.substr(cnt[c][0]+1,cnt[c][1]-cnt[c][0]-1);
  //cout<<re1<<endl<<re2<<endl<<rem<<endl;;
  if(a.size()%2 == b.size()%2){
    rem=c+rem;
    re1+=rem.substr(0,rem.size()/2);
    re2=rem.substr(rem.size()/2)+re2;
  }else{
    re1+=c+rem.substr(0,rem.size()/2);
    re2=rem.substr(rem.size()/2)+re2;
  }
  reverse(all(re2));
  cout<<re1<<endl<<re2<<endl;
  return 0;
}