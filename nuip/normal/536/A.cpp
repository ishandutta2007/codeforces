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
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  ll a,b,n,l,t,m,lb,rb,md;
  scanf("%I64d %I64d %I64d",&a,&b,&n);
  rep(i,n){
    scanf("%I64d %I64d %I64d",&l,&t,&m);
    --l;
    lb=l; rb=l+100000000;
    while(rb-lb>1){
      md=(rb+lb)/2;
      //cout<<"["<<l<<","<<md<<")"<<endl;
      //cout<<(md-l)*a+((md)*(md-1)/2 - (l-1)*(l)/2)*b<<endl;
      if(l==md || a+(md-1)*b<=t &&
	 (md-l)*a+((md)*(md-1)/2 - (l-1)*(l)/2)*b<=t*m){
	lb=md;
      }else{
	rb=md;
      }
    }
    printf("%I64d\n",(lb==l?-1ll:lb));
  }
  return 0;
}