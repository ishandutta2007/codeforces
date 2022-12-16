#include <stdio.h>
#define MN 100

int n,a[MN+5];

void print(int l,int r,int d){
	if(l>r) return;
	int m = l;
	for(int i=l;i<=r;i++)
		if(a[i]>a[m]) m = i;
	print(l,m-1,d+1);
	printf("%d ",d);
	print(m+1,r,d+1);
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	print(1,n,0);
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}