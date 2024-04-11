#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int main(){
  int m,n,i,j,k;
  ifstream ii("input.txt");
  ofstream oo("output.txt");;
  int a[50][50];
  int s[51],t[51];
  int x[3];
  ii>>n>>m;
  for(j=0;j<n;j++){
    for(i=0;i<m;i++){
      ii>>a[j][i];
    }
  }
  for(i=0;i<3;i++){
    ii>>x[i];
  }
  s[0]=0;
  t[0]=0;

  for(j=0;j<n;j++){
    k=0;
    for(i=0;i<m;i++)k+=a[j][i];
    t[j+1]=t[j]+k;
  }
  for(i=0;i<m;i++){
    k=0;
    for(j=0;j<n;j++)k+=a[j][i];
    s[i+1]=s[i]+k;
  }
  sort(x,x+3);
  int ans=0;
  do{
    for(j=1;j<n;j++){
      for(i=j+1;i<n;i++){
	if(x[0]==t[j]-t[0]&&x[1]==t[i]-t[j]&&x[2]==t[n]-t[i])ans++;
      }
    }
    for(j=1;j<m;j++){
      for(i=j+1;i<m;i++){
	if(x[0]==s[j]-s[0]&&x[1]==s[i]-s[j]&&x[2]==s[m]-s[i])ans++;
      }
    }
  }while(next_permutation(x,x+3));
  oo<<ans<<endl;
  return 0;
}