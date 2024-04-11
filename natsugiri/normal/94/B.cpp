#include<iostream>
using namespace std;
int main(){
  int n,a[5][5],i,j,k;
  for(i=0;i<5;i++)for(j=0;j<5;j++)a[i][j]=0;
  for(cin>>n,i=0;i<n;i++){
    cin>>j>>k;
    a[j-1][k-1]=a[k-1][j-1]=1;
  }
  for(k=0;k<5;k++){
    for(j=k+1;j<5;j++){
      for(i=j+1;i<5;i++){
    if(a[i][j]==a[i][k]&&a[i][j]==a[j][k]){
      cout<<"WIN"<<endl;
      return 0;
    }
      }
    }
  }
  cout<<"FAIL"<<endl;
  return 0;
}