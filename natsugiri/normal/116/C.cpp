#include<iostream>
using namespace std;
int main(){
  int n,i,j,p,m;
  cin>>n;
  int a[n],b[n];
  for(i=0;i<n;i++){
    cin>>a[i];
    b[i]=1;
  }
  m=0;
  for(i=0;i<n;i++){
    if(b[i]){
      p=1;
      for(j=i;a[j]>0;j=a[j]-1){
	b[j]=0;
	p++;
      }
      if(m<p)m=p;
    }
  }
  cout<<m<<endl;
  return 0;
}