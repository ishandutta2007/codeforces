#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long LL;
const LL MOD=1000000007;

int n, l, a[200], b[200];
int d[3110][200];
vector<int>G[200];

int main(){
  scanf("%d%d", &n, &l);
  for(int i=0; i<n; i++){
    scanf("%d%d", a+2*i, b+2*i);
    a[2*i+1]=b[2*i];
    b[2*i+1]=a[2*i];
    if(a[2*i]==b[2*i])a[2*i+1]=b[2*i+1]=0;
  }

  for(int i=0; i<2*n; i++)d[a[i]][i]=1;

  for(int i=1; i<l; i++){
    for(int j=0; j<2*n; j++){
      if(a[j]==0)continue;
      if(i+a[j]>l)continue;
      for(int k=0; k<2*n; k++){
	if(k/2*2==j/2*2)continue;
	if(a[j]==b[k]){
	  d[i+a[j]][j]=((LL)d[i+a[j]][j]+d[i][k])%MOD;
	}
      }
    }
  }

  int ans=0;
  for(int i=0; i<2*n; i++)ans=((LL)ans+d[l][i])%MOD;
  printf("%d\n", ans);
  return 0;
}