#include <stdio.h>
#define MN 1000

int n,x,a[MN+5];

bool check0(){
	for(int i=1;i<=n;i++)
		if(a[i]!=x) return false;
	return true;
}

bool check1(){
	int s = n*x;
	for(int i=1;i<=n;i++)
		if(a[i]==x) return true;
	for(int i=1;i<=n;i++)
		s -= a[i];
	return s==0;
}

void solve(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(check0()){
		puts("0");
		return;
	}
	if(check1()){
		puts("1");
		return;
	}
	puts("2");
	return;
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}