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

const int SQ=777;
typedef pair<pii,int> piii;

const int nn=1123456;
int bit[nn+1];
int dat2[nn+1];

int sum(int i,int *bit=bit){ //++i; // comment out : [0,i)
  ll s=0;
  while(i>0){
    s^=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(int i,int x,int *bit=bit){ ++i;
  while(i<=nn){
    bit[i]^=x;
    i+=i&-i;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  scanf("%d",&n); //cin>>n;
  vector<int> a(n);
  rep(i,n) scanf("%d",&a[i]); //cin>>a[i];
  int q;
  scanf("%d",&q); //cin>>q;
  vector<pii> qs;
  vv<int> lb(n);
  rep(i,q){
    int x,y;
    scanf("%d%d",&x,&y); //cin>>x>>y;
    --x;
    qs.eb(x,y);
    lb[x].pb(i);
  }
  vector<int> re(q);
  unordered_map<int,int> pre;
  rrep(i,n){
    if(pre.count(a[i])) add(pre[a[i]],a[i],dat2);
    pre[a[i]]=i;
    add(i,a[i],dat2);
    for(int j:lb[i]) re[j]^=sum(qs[j].X,dat2)^sum(qs[j].Y,dat2);
    //for(int j:lb[i]) cout<<qs[j];cout<<endl;
    //for(auto p:pre) cout<<p;cout<<endl;
  }
  //cout<<re;
  rep(i,n) add(i,a[i]);
  rep(i,q){
    re[i]^=sum(qs[i].X)^sum(qs[i].Y);
  }
  //cout<<re;
  for(int x:re) printf("%d\n",x); //cout<<x<<endl;
  return 0;
}