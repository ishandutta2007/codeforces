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
  int n,m,l,t;
  cin>>n>>m>>l>>t;
  string s;
  cin>>s;
  s+="1"; ++n;
  priority_queue<pii> q;
  int sum=0;
  int cnt=0;
  rep(i,n){
    if(s[i]=='1'){
      q.emplace(cnt,i-cnt);
      sum+=cnt/l;
      cnt=0;
    }else{
      ++cnt;
    }
  }
  vector<int> re;
  while(q.size()){
    pii p=q.top(); q.pop();
    int x=p.X,y=p.Y;
    sum-=x/l;
    int a=l-1,b=x-a-1;
    re.pb(y+a);
    sum+=a/l+b/l;
    //cout<<sum<<p<<a<<endl;
    q.emplace(a,y); q.emplace(b,y+a+1);
    if(sum<m) break;
  }
  cout<<re.size()<<endl;
  for(int x:re) cout<<x+1<<" ";cout<<endl;
  return 0;
}