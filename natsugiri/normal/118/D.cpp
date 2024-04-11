#include<iostream>
#include<cstring>
using namespace std;
#define MOD ((int)1e8)
int a[2][10][101][101];
int main(){
  int n,m,k,l,x,y,t;

  cin>>n>>m>>k>>l;
  memset(a,0,sizeof(a));
  a[0][0][0][1]=a[1][0][1][0]=1;
  for(x=0;x<=n;x++){
    for(y=0;y<=m;y++){
      if(x+y<2)continue;
      for(t=0;t<l;t++){
	a[0][0][y][x]+=a[1][t][y][x-1];
	a[0][0][y][x]%=MOD;
      }
      for(t=1;t<k;t++){
	a[0][t][y][x]=a[0][t-1][y][x-1];
	a[0][t][y][x]%=MOD;
      }
      for(t=0;t<k;t++){
	a[1][0][y][x]+=a[0][t][y-1][x];
	a[1][0][y][x]%=MOD;
      }
      for(t=1;t<l;t++){
	a[1][t][y][x]=a[1][t-1][y-1][x];
	a[1][t][y][x]%=MOD;
      }
    }
  }
  x=0;
  for(t=0;t<10;t++){
    x+=a[0][t][m][n];
    x+=a[1][t][m][n];
    x%=MOD;
  }
  cout<<x<<endl;
  return 0;
}