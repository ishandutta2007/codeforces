#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

#define MOD 1000000007

string str;
long long d[101][2501];

int main(){
  int n,i,j,k;

  d[0][0]=1;
  for(j=1;j<101;j++){
    for(i=0;i<2501;i++){
      for(k=0;k<26;k++){
	if(i<k)continue;
	d[j][i]=(d[j][i]+d[j-1][i-k])%MOD;
      }
    }
  }

  cin>>n;
  for(;n--;){
    cin>>str;
    for(i=k=0;i<(int)str.size();i++){
      k+=str[i]-'a';
    }
    printf("%lld\n",d[str.size()][k]-1);
  }
  return 0;
}