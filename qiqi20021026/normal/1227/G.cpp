#include<bits/stdc++.h>

using namespace std;

#define N 1200

int n,a[N];
bool f[N][N];

void solve(int u,int d,int l,int r){
	if (u==d) return;
	int t=a[l];
	for (int i=1;i<=t;++i) f[u+i-1][l]=1;
	for (int i=l+1;i<=l+t-1;++i){
		int x=min(a[i],t-1);
		for (int j=1;j<=a[i]-x;++j){
			f[u+t+j-1][i]=1;
		}
		a[i]=x;
	}
	int t2=d-u+1-t;
	for (int i=l+t;i<=r;++i){
		int x=min(a[i],t2-1);
		for (int j=1;j<=a[i]-x;++j){
			f[u+j-1][i]=1;
		}
		a[i]=x;
	}
	solve(u,u+t-1,l+1,l+t-1);
	solve(u+t,d,l+t,r);
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	solve(1,n+1,1,n);
	printf("%d\n",n+1);
	for (int i=1;i<=n+1;++i){
		for (int j=1;j<=n;++j) putchar(f[i][j]+'0');
		puts("");
	}
	
	return 0;
}