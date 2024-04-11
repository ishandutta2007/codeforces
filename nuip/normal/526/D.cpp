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


void kmp(const string &str,vector<int> &re){
  re.resize(str.size()+1); re[0]=-1;
  int j=-1;
  rep(i,str.size()){
    while(j>=0 && str[i]!=str[j]) j=re[j];
    re[i+1]=++j;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  ll n,t;
  string str;
  cin>>n>>t>>str;
  vector<int> v,re(n+10);
  kmp(str,v);
  ll p;
  for(p=1;p<=n;++p){
    if(str[p]!=str[p-1])break;
  }
  for(ll i=1;i*t<=p;++i){
    if(i*(t+1)<p){
      ++re[i*t-1]; --re[i*(t+1)];
    }else{
	++re[i*t-1]; --re[p];
    }
  }
  for(ll d=2;d<=n;++d){
    for(p=1;(p+1)*d<=n;++p){
      if(v[(p+1)*d]!=p*d)break;
    }
    //cout<<d<<":"<<p<<endl;
    //if(p==1)continue;
    ll l=p*d,r=(p+1)*d+1,m;
    while(r-l>1){
      m=(l+r)/2;
      if(m<=n && v[m]==m-d)
	l=m;
      else
	r=m;
      //cout<<l<<","<<r<<endl;
    }
    for(ll i=1;i<=p/t;++i){
      if(d*i*(t+1)<l){
	++re[d*i*t-1]; --re[d*i*(t+1)];
	//cout<<"["<<d*i*t-1<<","<<d*i*(t+1)<<"),";
      }else{
	++re[d*i*t-1]; --re[l];
	//cout<<"["<<d*i*t-1<<","<<l<<"),";
      }
    }//cout<<endl;
  }
  rep(i,n)
    re[i+1]+=re[i];
  rep(i,n)
    cout<<int(re[i]>0);
  cout<<endl;
  return 0;
}