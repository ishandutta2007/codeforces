#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,ans,a[3000],b[3000],f[8000000];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){scanf("%d",&a[i]); f[a[i]]=1;}
	for (int i=1;i<=n;i++){scanf("%d",&b[i]); f[b[i]]=1;}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (f[a[i]^b[j]]) ans++;
	puts(ans&1?"Koyomi":"Karen");
	return 0;
}