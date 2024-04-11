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
  int n;
  cin>>n;
  string a,b;
  cin>>a>>b;
  typedef pair<char,char> pcc;
  map<pcc,int> st;
  map<char,int> A,B;
  pii re;
  int ret=0;
  rep(i,n)
    if(a[i]!=b[i]){
      ++ret;
      A[a[i]]=i; B[b[i]]=i;
      st[pcc(a[i],b[i])]=i;
    }
  int f=0;
  for(auto c:A)
    if(B.count(c.X)){
      f=1; re=pii(c.Y,B[c.X]);
      break;
    }
  if(!f){
    cout<<ret<<endl;
    cout<<"-1 -1"<<endl;
    return 0;
  }
  
  for(auto p:st){
    pcc tmp=pcc(p.X.Y,p.X.X);
    if(st.count(tmp)){
      f=2; re=pii(p.Y,st[tmp]);
      break;
    }
  }
  cout<<ret-f<<endl;
  cout<<re.X+1<<" "<<re.Y+1<<endl;
  return 0;
}