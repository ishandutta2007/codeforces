#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int n,m,x,y;
double a[1111][1111];
double b[1111],c[1111];

int main(){
  cin>>n>>m;
  cin>>x>>y;
  if(m==1){
    printf("%.4lf\n",2.*(n-x));
    return 0;
  }else{
    for(int i=n-1;i>=1;i--){
      b[1] = -0.5;
      c[1] = (1+a[i+1][1]/3)*3/2;
      for(int j=2;j<m;j++){
	b[j] = -1./4 / (0.75 + b[j-1]/4);
        c[j] = (1 + a[i+1][j]/4 + c[j-1]/4) / (0.75 + b[j-1]/4.0);
      }
      b[m] = 2/3. + b[m-1]/3;
      c[m] = 1 + a[i+1][m]/3 + c[m-1]/3;
      a[i][m] = c[m]/b[m];
      for(int j = m-1;j>=1;j--){
	a[i][j] = c[j] - a[i][j+1]*b[j];
      }
    }
  }
  printf("%.4lf\n",a[x][y]);
  return 0;
}