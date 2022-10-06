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

int main(){
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(0);
  int n,q;
  scanf("%d%d",&n,&q);
  int s=0;
  int t,x,cnt=0,fst=0;
  rep(i,q){
    scanf("%d",&t);
    if(t==1){
      scanf("%d",&x);
      (s+=n-x)%=n;
    }else{
      if(!cnt){
	++cnt;
	fst=s%2;
      }else{
	if((cnt+fst+1)%2==s%2){
	  --cnt;
	}else{
	  ++cnt;
	}
      }
    }
  }
  //cout<<vs;
  vector<int> re(n);
  if(cnt){
    rep(i,n){
      if((i+fst)%2){
	re[(i-cnt%n+n)%n]=i;
      }else{
	re[(i+cnt)%n]=i;
      }
    }
  }else{
    iota(all(re),0);
  }
  //cout<<s<<re;
  rep(i,n){
    if(i)printf(" ");
    printf("%d",re[(s+i)%n]+1);
  }
  printf("\n");
  return 0;
}