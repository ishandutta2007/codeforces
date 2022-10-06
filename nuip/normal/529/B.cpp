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

const ll INF=1e15;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n;
  scanf("%d",&n);
  vector<ll> h(n),w(n);
  vector<ll> val(n);
  rep(i,n)
    scanf("%I64d %I64d",&w[i],&h[i]);
  ll re=INF,sum;
  int f,lie;
  rep(hei,1001)if(hei){
    sum=0; lie=n/2; fill(all(val),1); f=0;
    rep(i,n){
      if(h[i]<=hei){
	sum+=w[i];
	if(w[i]<=hei)
	  val[i]=h[i]-w[i];
      }else if(w[i]<=hei){
	sum+=h[i];
	--lie;
      }else{
	f=1;
	break;
      }	
    }
    if(f)
      continue;
    if(lie<0)
      continue;
    //cout<<sum<<val;
    sort(all(val));
    rep(i,lie){
      if(val[i]>=0)break;
      sum+=val[i];
    }
    //cout<<sum<<endl;
    re=min(re,hei*sum);
  }
  //cout<<re<<","<<area<<endl;
  cout<<re<<endl;
  return 0;
}