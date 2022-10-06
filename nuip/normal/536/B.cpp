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

void zAlgo(const string &str,vector<int> &re){
  re.resize(str.size()); re[0]=str.size();
  int i=1,j=0;
  while(i<str.size()){
    while(i+j<str.size() && str[j]==str[i+j]) ++j;
    re[i]=j;
    if(!j){++i; continue;}
    int k=1;
    while(i+k<str.size() && k+re[k]<j){
      re[i+k]=re[k]; ++k;
    }
    i+=k; j-=k;
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,m,len;
  scanf("%d %d",&n,&m);
  char str_[n+1];
  scanf("%s",str_);
  string str(str_);
  len=str.size();
  vector<int> p(m),z,sum(n+1);
  rep(i,m){
    scanf("%d",&p[i]);
    --p[i];
  }
  zAlgo(str,z);
  //cout<<z;
  rep(i,m-1){
    if(p[i+1]-p[i]<len && z[p[i+1]-p[i]]+p[i+1]-p[i]<len){
      printf("0\n");
      return 0;
    }
  }
  rep(i,m){
    ++sum[p[i]]; --sum[p[i]+len];
  }
  //cout<<sum;
  rep(i,n-1)
    sum[i+1]+=sum[i];
  //cout<<sum;
  ll re=1,MOD=1e9+7;
  rep(i,n)if(sum[i]==0)
    (re*=26)%=MOD;
  printf("%I64d\n",re);
  return 0;
}