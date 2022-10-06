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
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<int> edge[112345];
int n,color[112345];
ll MOD=1e9+7;

ll powl(ll n,ll m){
  if(m==0)return 1;
  ll tmp=powl(n,m/2);
  return tmp*tmp%MOD*(m%2?n:1)%MOD;
}

ll inv(ll n){
  return powl(n,MOD-2)%MOD;
}

pll solve(int c,int p){
  ll sum=0,prod=1;
  int i,j,k;
  vector<pll> res;
  rep(i,edge[c].size()){
    if(edge[c][i]==p)
      continue;
    res.pb(solve(edge[c][i],c));
  }
  rep(i,res.size()){
    prod*=(res[i].X+res[i].Y)%MOD;
    prod%=MOD;
  }
  if(color[c]){
    return pll(prod,0ll);
  }else{
    rep(i,res.size()){
      sum+=prod*inv((res[i].X+res[i].Y)%MOD)%MOD*res[i].X%MOD;
      sum%=MOD;
    }
    return pll(sum,prod);
  }
}

int main(){
  int i,j,k,tmp;
  cin>>n;
  rep(i,n-1){
    cin>>tmp;
    edge[tmp].pb(i+1);
    edge[i+1].pb(tmp);
  }
  rep(i,n)
    cin>>color[i];
  cout<<solve(0,0).X%MOD<<endl;
  return 0;
}