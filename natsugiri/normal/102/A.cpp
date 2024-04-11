#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
  int n,m,a[101][101],p[101],i,j,k,mi;
  cin>>n>>m;
  mi=-1;
  memset(a,0,sizeof(a));
  for(i=0;i<n;i++)cin>>p[i];
  for(i=0;i<m;i++){
    cin>>j>>k;
    a[j-1][k-1]=a[k-1][j-1]=1;
  }
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(k=j+1;k<n;k++){
	if(a[i][j]&a[j][k]&a[k][i]){
	  if(mi<0||mi>p[i]+p[j]+p[k])mi=p[i]+p[j]+p[k];
	}
      }
    }
  }
  cout<<mi<<endl;
  return 0;
}