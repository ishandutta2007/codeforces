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
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int a[2][30][112345],re[112345],sum[30][112345];

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k;
  int n,m,l,r,q;
  vector<int> vl,vr,vq;
  cin>>n>>m;
  rep(i,m){
    cin>>l>>r>>q;
    vl.pb(l),vr.pb(r),vq.pb(q);
    l--;
    rep(j,30){
      a[((q&(1<<j))>0)][j][l]++;
      a[((q&(1<<j))>0)][j][r]--;
    }
  }
  rep(k,2)
  rep(i,30)
    rep(j,n)
      a[k][i][j+1]+=a[k][i][j];
  rep(i,30)
    rep(j,n){
      sum[i][j+1]=a[1][i][j]=min(1,a[1][i][j]);
      re[j]|=(1<<i)*(a[1][i][j]>0);
    }
  rep(i,30)
    rep(j,n)
      sum[i][j+1]+=sum[i][j];
 // rep(i,30){rep(j,n+1)cout<<sum[i][j]<<" ";cout<<endl;}
  int f=0,f2=0;
  rep(i,m){
   // cout<<vl[i]<<","<<vr[i]<<","<<vq[i]<<endl;
    rep(j,30){
      if((vq[i]&(1<<j)) == 0){
      //  cout<<sum[j][vr[i]]<<","<<sum[j][vl[i]-1]<<endl;
        if(sum[j][vr[i]]-sum[j][vl[i]-1]
           ==vr[i]-vl[i]+1)
          f=1;
      }
    }
  }
  if(f){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
    rep(i,n)
      cout<<re[i]<<" ";cout<<endl;
  }
  return 0;
}