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

ll solve(vector<int> a){
  int h=a[1]+a[2];
  vector<int> l(a[5],1),r(a[1],1),len(h);
  l.resize(h); r.resize(h);
  rep(i,h)
    len[i]=(l[i]+r[i])-1;
  len[0]+=a[0];
  rep(i,h-1)
    len[i+1]+=len[i];
  ll re=0;
  //  cout<<len;
  return accumulate(all(len),0ll);
  rep(i,h){
    //cout<<"["<<i<<"]"<<endl;
    int x=len[i];
    re+=x;
    for(int j=i+1;j<h;++j){
      x+=l[j]+r[j]-2;
      cout<<j<<":"<<x<<endl;
      if(x<=0)break;
      re+=x;
    }
  }
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  vector<int> a(6);
  rep(i,6)
    cin>>a[i];
  //cout<<solve(a)<<solve({a[3],a[4],a[5],a[0],a[1],a[2]})<<endl;
  cout<<solve(a)+solve({a[3],a[4],a[5],a[0],a[1],a[2]})<<endl;
  return 0;
}