#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[101],b[101];
double f[2][101][10001],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=0;i<=100;i++)
	for(int j=0;j<=10000;j++)
	f[0][i][j]=f[1][i][j]=-(1<<30);
	f[0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i*100;k++){
				f[i&1][j][k]=f[i&1^1][j][k]+b[i]*1.0/2;
				if(j&&k>=a[i]) f[i&1][j][k]=max(f[i&1][j][k],f[i&1^1][j-1][k-a[i]]+b[i]);
			}
		}
	}
	for(int t=1;t<=n;t++){
		ans=0;
		for(int i=1;i<=10000;i++) ans=max(ans,min(f[n&1][t][i],1.0*i));
		printf("%.9lf ",ans);
	}
}