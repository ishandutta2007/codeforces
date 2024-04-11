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

int ok[4][11234];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  string str;
  cin>>str;
  int n=str.size();
  ok[2][n-2]=ok[3][n-3]=1;
  set<string> re;
  if(n>6) re.insert(str.substr(n-2));
  if(n>7) re.insert(str.substr(n-3));
  rrep(i,n){
    if(i<5) break;
    for(int j=2;j<=3;++j){
      if(ok[j][i+j] && str.substr(i,j)!=str.substr(i+j,j)
	 || ok[5-j][i+j]){
	ok[j][i]=1;
	re.insert(str.substr(i,j));
      }
    }
  }
  cout<<re.size()<<endl;
  for(const string &s:re) cout<<s<<endl;
  return 0;
}