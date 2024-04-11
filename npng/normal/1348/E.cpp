#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[510],b[510];
int f[510],g[510];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	long long A=0,B=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		A+=a[i];
		B+=b[i];
	}
	long long ans=A/k+B/k;
	A%=k;
	B%=k;
	if((A+B)>=k){
		f[0]=1;
		for(int i=1;i<=n;i++){
			memset(g,0,sizeof g);
			for(int j=1;j<k;j++){
				if(j<=a[i]&&k-j<=b[i]){
					for(int x=0;x<k;x++){
						if(f[x])g[(x+j)%k]=1;
					}
				}
			}
			for(int j=0;j<k;j++){
				f[j]|=g[j];
			}
		}
		for(int i=1;i<k;i++)
			if(f[i]&&i<=A&&k-i<=B){
				ans++;
				break;
			}
	}
	printf("%I64d\n",ans);
	return 0;
}