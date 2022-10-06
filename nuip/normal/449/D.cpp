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
//--
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

int findsign(int n){
  int re=1;
  while(n){
    if(n%2)
      re*=-1;
    n/=2;
  }
  return re;
}
ll mod=1e9+7;
ll poww(ll a,ll b){
  if(!b)return 1;
  ll tmp=poww(a,b/2);
  return tmp*tmp%mod*(b%2?a:1)%mod;
}
ll a[1123456],dp[1<<20];
int main(){
  ll i,j,k,n,re=0;
  cin>>n;
  rep(i,n){
    cin>>a[i];
    dp[a[i]]++;
  }  //rep(i,20)cout<<dp[i]<<",";cout<<endl;
  rep(i,20){
    //cout<<i<<endl;
    rep(j,1<<20)
      if(!(j&(1<<i)))dp[j]+=dp[j|(1<<i)];
  //  rep(ii,20)cout<<dp[ii]<<",";cout<<endl;
  }
//  cout<<poww(2,10)<<endl;
//  cout<<poww(10,5)<<endl;
  for(i=0;i<(1<<20);i++){
    ll sign=findsign(i),sum=1,su;//cout<<i<<endl;
    sum=poww(2ll,dp[i]);
    sum--;
    re=(re+sign*sum+mod)%mod;
//    cout<<dp[i]<<","<<re<<endl;
  }
  cout<<(re+mod)%mod<<endl;
  return 0;
}