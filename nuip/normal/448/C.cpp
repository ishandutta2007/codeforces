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

int a[5123],memo[5123][5123];

ll solve(int l,int r,ll del){
//  cout<<l<<" "<<r<<endl;
  if(l>=r)return 0;
  if(memo[l][r])
    return memo[l][r];
  ll re=0;
  int mn=2e9,i,j,k;
  for(i=l;i<r;i++)
    mn=min(mn,a[i]);
  int pre=l;
  for(i=l;i<r;i++){
    if(a[i]!=mn)continue;
    re+=solve(pre,i,mn);
    pre=i+1;
  }
  re+=solve(pre,r,mn);
  return memo[l][r]=min(re+mn-del,r-l+0ll);
}

int main(){
  int i,j,k,n;
  cin>>n;
  rep(i,n)
    cin>>a[i];
  cout<<solve(0,n,0)<<endl;
  //rep(i,10){rep(j,10)cout<<memo[i][j]<<" ";cout<<endl;}
  return 0;
}