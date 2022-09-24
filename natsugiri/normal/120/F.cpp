#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
  ifstream ii("input.txt");
  ofstream oo("output.txt");
  int n,b[111][111],t,i,j,k,x,y;
  int ans=0;
  ii>>n;
  for(;n--;){
    ii>>t;
    for(j=0;j<t;j++)for(i=0;i<t;i++)b[j][i]=-1;
    for(i=0;i<t;i++)b[i][i]=0;
    for(i=1;i<t;i++){
      ii>>x>>y;
      x--;y--;
      b[x][y]=b[y][x]=1;
    }
    for(k=0;k<t;k++){
      for(i=0;i<t;i++){
	for(j=0;j<t;j++){
	  if(b[i][k]>=0&&b[k][j]>=0&&(b[i][j]<0||b[i][j]>b[i][k]+b[k][j])){
	    b[i][j]=b[i][k]+b[k][j];
	  }
	}
      }
    }
    x=0;
    for(j=0;j<t;j++){
      for(i=0;i<t;i++){
	if(x<b[j][i])x=b[j][i];
      }
    }
    ans+=x;
  }
  oo<<ans<<endl;
}