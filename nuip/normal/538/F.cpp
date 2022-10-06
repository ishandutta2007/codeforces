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

const int nn=212345;
int bit[nn+1];
int sum(int i){
  ++i;
  i=min(i,nn);
  int s=0;
  while(i>0){
    s+=bit[i];//ok?
    i-=i&-i;
  }
  return s;
}

void add(int i,int x){
  ++i;
  while(i<=nn){
    bit[i]+=x;
    i+=i&-i;
  }
}
const int sq=500;
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n;
  scanf("%d",&n);
  vector<pii> v(n);
  vector<int> re(n),re2(212345);
  rep(i,n){
    scanf("%d",&v[i].X);
    v[i].Y=i;
  }
  sort(all(v));
  rep(i,n){
    repe(k,sq)if(k){if(k>=n)break;
      //      cout<<"add["<<k*v[i].Y+1<<","<<(v[i].Y+1)*k<<"]"<<endl;
      re[k]+=sum((v[i].Y+1)*k)-sum(k*v[i].Y);
      //cout<<sum((v[i].Y+1)*k)-sum(k*v[i].Y)<<endl;
    }
    //cout<<i<<"!"<<endl;
    if(v[i].Y<sq)
      peat(k,n){
	re[k]+=sum((v[i].Y+1)*k)-sum(k*v[i].Y);
      }
    //cout<<"add "<<v[i].Y<<endl;
    add(v[i].Y,1);
  }
  rep(i,n)if(i)
    printf("%d ",re[i]);
  printf("\n");
  return 0;
}