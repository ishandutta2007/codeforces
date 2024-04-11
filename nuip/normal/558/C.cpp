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
  vector<int> a(n);
  rep(i,n)
    cin>>a[i];
  sort(all(a));
  int lng=0,re=11234567,sum;
  for(int tt=a[0];tt;tt>>=1){
    int t=tt;
    while(t){
      int f=1; sum=0;
      for(int s:a){
	const int tmp=__builtin_clz(t)-__builtin_clz(s);
	//cout<<t<<","<<s<<":"<<tmp<<endl;
	if(s<t)
	  s<<=-tmp;
	else
	  s>>=tmp;
	sum+=abs(tmp);
	if(s!=t){
	  if((s|t)!=s){ f=0; continue;}
	  //cout<<pii(s,t)<<__builtin_clz(t^s)<<endl;
	  sum+=2*(32-__builtin_clz(t^s))+(tmp<0?tmp:0)*2;
	}
      }
      //if(f)cout<<t<<":"<<sum<<endl;
      if(f)re=min(sum,re);
      //if(t>a.back()) break;
      t<<=1;
    }
  }
  cout<<re<<endl;
  return 0;
}