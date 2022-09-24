#include<cstdio>
#include<iostream>
using namespace std;
int main(){
  char ch[128][128];
  int i,j,x,y,a[128][128],n,m;
  cin>>n>>m;
  for(i=0;i<128;i++)for(j=0;j<128;j++)a[i][j]=1;
  for(j=0;j<n;j++){
    scanf("%s",ch[j]);
  }
  for(j=0;j<n;j++){
    for(i=0;i<m;i++){
      for(y=j+1;y<n;y++){
    if(ch[j][i]==ch[y][i]){
      a[j][i]=a[y][i]=0;
    }
      }
      for(x=i+1;x<m;x++){      
    if(ch[j][i]==ch[j][x]){
      a[j][i]=a[j][x]=0;
    }
      }
    }
  }
  for(j=0;j<n;j++){
    for(i=0;i<m;i++){
      if(a[j][i]){
    cout<<ch[j][i];
      }
    }
  }
  cout<<endl;
  
  return 0;
}