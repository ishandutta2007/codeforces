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
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  ll n,m,la,lb,gcd,lcm;
  string a,b,st[2];
  cin>>n>>m>>a>>b;
  st[0]=a;
  st[1]=b;
  la=a.size();
  lb=b.size();
  gcd=__gcd(la,lb);
  lcm=la/gcd*lb;
  ll v[2][26];
  ll re=0;
  rep(g,gcd){
    fill(v[0],v[0]+52,0ll);
    rep(i,2)
    rep(j,st[i].size()/gcd)
      v[i][st[i][j*gcd+g]-'a']++;
    rep(i,26)
      re+=v[0][i]*v[1][i];
  }
  re*=la*n/lcm;
  cout<<la*n-re<<endl;
  return 0;
}