#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
  int n,p,a,b,d,i,j,t,m,k;
  cin>>n>>p;
  int v[n][n],tank[n],w[n][3];
  
  memset(v,0,sizeof(v));
  memset(tank,0,sizeof(tank));
  for(i=0;i<p;i++){
    cin>>a>>b>>d;
    v[a-1][b-1]=d;
    tank[a-1]++;
    tank[b-1]--;
  }
  t=0;
  for(i=0;i<n;i++){
    if(tank[i]>0){
      m=9999999;
      k=i;
      for(;tank[k]>-1;){
	for(j=0;j<n;j++){
	  if(v[k][j]>0){
	    m=min(m,v[k][j]);
	    k=j;
	    break;
	  }
	}
      }
      w[t][0]=i+1;
      w[t][1]=k+1;
      w[t][2]=m;
      t++;
    }
  }

  cout<<t<<endl;
  for(i=0;i<t;i++){
    cout<<w[i][0]<<" "<<w[i][1]<<" "<<w[i][2]<<endl;
  }
	
  return 0;
}