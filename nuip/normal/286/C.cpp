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
  scanf("%d",&n);
  vector<int> a(n),sgn(n),re(n);
  rep(i,n)
    scanf("%d",&a[i]);
  int m,t;
  scanf("%d",&m);
  rep(i,m){
    scanf("%d",&t);
    sgn[n-t]=1;
  }
  reverse(all(a));
  stack<int> st;
  st.push(-1);
  rep(i,n){
    if(st.top()==a[i] && !sgn[i]){
      st.pop();
      re[i]=-a[i];
    }else{
      st.push(a[i]);
      re[i]=a[i];
    }
  }
  if(st.top()==-1){
    printf("YES\n");
    rrep(i,n)
      printf("%d ",-re[i]);
    printf("\n");
  }else{
    printf("NO\n");
  }
  return 0;
}