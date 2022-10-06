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
  int n;
  cin>>n;
  int kx,ky;
  cin>>kx>>ky;
  vector<pii> atk(8,pii(MOD,0));
  for(int i:{2,4,5,3}) atk[i].X=-MOD;
  rep(i,n){
    string s; int x,y;
    cin>>s>>x>>y;
    if(x==kx){
      if(y>ky) MN(atk[6],pii(y,s[0]));
      else MX(atk[2],pii(y,s[0]));
    }else if(y==ky){
      if(x>kx) MN(atk[0],pii(x,s[0]));
      else MX(atk[4],pii(x,s[0]));
    }else if(x-y==kx-ky){
      if(x>kx) MN(atk[1],pii(x,s[0]));
      else MX(atk[5],pii(x,s[0]));
    }else if(x+y==kx+ky){
      if(x>kx) MN(atk[7],pii(x,s[0]));
      else MX(atk[3],pii(x,s[0]));
    }
  }
  int f=0;
  rep(i,8){
    if(i%2==0 && atk[i].Y && atk[i].Y!='B') f=1;
    if(i%2==1 && atk[i].Y && atk[i].Y!='R') f=1;
  }
  //cout<<atk;
  cout<<(f?"YES":"NO")<<endl;
  return 0;
}