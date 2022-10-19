#include<bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int n,mn,sum,lst,a[1200],b[1200],f[1200],g[1200];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (;!a[n];--n);
	for (int i=n;i>=1;--i){
		int x=max(a[i]-1,0),y=max(a[i+1]-1,0);
		if (y>=x) f[i]=f[i+1]+3*x;
		else f[i]=f[i+1]+3*y+5*(x-y);
	}
	for (int i=1;i<=n;++i){
		int x=a[i],y=a[i-1];
		if (y>=x) g[i]=g[i-1]+3*x;
		else g[i]=g[i-1]+3*y+5*(x-y);
	}
	lst=1;
	for (int i=2;i<=n;++i)
		if (f[i]+g[i-1]+2*(i-1)+3*(n-i+1)+2<f[lst]+g[lst-1]+2*(lst-1)+3*(n-lst+1)+2)
			lst=i;
	for (int i=lst;i<=n;++i) if (a[i]) --a[i];
	for (int i=1;i<=n;++i) sum+=a[i];
	int i=-1,j;
	for (;sum;++i){
		while (a[i+2]){
			for (j=i+2,--a[j];j<n&&a[j+1];++j,--a[j]);
			sum-=(j-(i+2)+1);
			for (int k=i;k<j-1;++k){
				putchar('A'); putchar('R');
			}
			putchar('A');
			for (int k=j-1;k>i;--k) putchar('L');
			putchar('A');
		}
		if (sum){putchar('A'); putchar('R');}
		else break;
	}
	for (;i+1<n;++i){
		putchar('A'); putchar('R');
	}
	putchar('A');
	for (;i+2>lst;--i) putchar('L');
	putchar('A');
	
	return 0;
}