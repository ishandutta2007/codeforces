#include<iostream>
using namespace std;
char a[10][10];
int m,n;
int main(){
  int i,j,t;
  cin>>n>>m;
  for(j=0;j<n;j++){
    for(i=0;i<m;i++){
      cin>>a[j][i];
    }
  }
  t=0;
  for(j=0;j<n;j++){
    for(i=0;i<m;i++){
      if(a[j][i]=='W'){
	if(0<j&&a[j-1][i]=='P')a[j-1][i]='p',t++;
	else if(0<i&&a[j][i-1]=='P')a[j][i-1]='p',t++;
	else if(j<n-1&&a[j+1][i]=='P')a[j+1][i]='p',t++;
	else if(i<m-1&&a[j][i+1]=='P')a[j][i+1]='p',t++;
      }
    }
  }
  cout<<t<<endl;
  
  return 0;
}