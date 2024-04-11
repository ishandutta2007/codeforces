#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;
vector<string>v;
int n,m;

int main(){
  cin>>n>>m;
  int i,j,t;
  int x,y,z;
  int a[n][2];
  string s;
  for(i=0;i<n;i++){
    cin>>s;
    v.push_back(s);
  }
  for(j=0;j<n;j++){
    a[j][0]=a[j][1]=-1;
  }
  for(j=0;j<n;j++){
    for(i=0;i<m;i++){
      if(v[j][i]=='W'){
	a[j][1]=i;
      }
      if(v[j][m-i-1]=='W'){
	a[j][0]=m-i-1;
      }
    }
  }
  for(j=n-1;j>-1;j--){
    if(a[j][0]!=-1)break;
    n=j;
  }
  if(n==0){
    cout<<0<<endl;
    return 0;
  }
  t=0;
  i=0;
  for(j=0;j<n-1;j++){
    if(j%2){
      x=a[j][0];
      y=a[j+1][0];
      if(x<0)x=i;
      if(y<0)y=i;
      z=min(i,min(x,y));
      t+=abs(i-z);
      i=z;
    }else{
      x=a[j][1];
      y=a[j+1][1];
      if(x<0)x=i;
      if(y<0)y=i;
      z=max(i,max(x,y));
      t+=abs(i-z);
      i=z;
    }
    t++;
  }
  t+=abs(a[j][(j+1)%2]-i);
  cout<<t<<endl;
  return 0;
}