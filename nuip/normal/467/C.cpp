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

ll dp[5123][5123],n,m,t,a[5123],sum[11234];

int main(){
  int i,j,k;
  cin>>n>>m>>t;
  rep(i,n)
    cin>>a[i];
  for(i=m;i<=n;i++)
    for(j=1;j<=m;j++)
      sum[i]+=a[i-j];
  //rep(i,n)cout<<sum[i]<<" ";cout<<endl;
  for(i=m;i<=n;i++){
    for(j=1;j<=t;j++){
      dp[i][j]=max(dp[i-1][j],dp[i-m][j-1]+sum[i]);
    //  cout<<dp[i][j]<<" ";
    }//cout<<endl;
  }
  cout<<dp[n][t]<<endl;
  return 0;
}