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
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define rep(i,n) for( i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define all(X) (X).begin(),(X).end()
#define FUN(i,j) (i)*m+j
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int INF=1000000,d[412][412];

int main(){
  int n,m,i,j,k;
  string str;
  fill(d[0],d[0]+412*412,1);
  rep(i,412)
    d[i][i]=0;
  cin>>n>>m;
  cin>>str;
  rep(i,n){
      rep(j,m-1){
	if(str[i]=='>'){
	  d[FUN(i,j)][FUN(i,j+1)]=0;
	}else{
	  d[FUN(i,j+1)][FUN(i,j)]=0;
	}
	//	cout<<FUN(i,j)<<","<<FUN(i,j+1)<<endl;
      }
  }
  /* rep(i,n*m){
    rep(j,n*m)
      cout<<d[i][j]<<",";
    cout<<endl;
    }cout<<endl;*/
  cin>>str;
  rep(j,m){
      rep(i,n-1){
	if(str[j]=='v'){
	  d[FUN(i,j)][FUN(i+1,j)]=0;
	}else{
	  d[FUN(i+1,j)][FUN(i,j)]=0;
	}
	//		cout<<FUN(i,j)<<","<<FUN(i+1,j)<<endl;
      }
  }
  /*  rep(i,n*m){
    rep(j,n*m)
      cout<<d[i][j]<<",";
    cout<<endl;
    }cout<<endl;*/
  rep(k,n*m)
    rep(i,n*m)
    rep(j,n*m)
    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  /* rep(i,n*m){
    rep(j,n*m)
      cout<<d[i][j]<<",";
    cout<<endl;
    }*/
int f=0;
  rep(i,n*m)
    rep(j,n*m)
    f|=d[j][i];
  cout<<(f?"NO":"YES")<<endl;
  return 0;
}