#include <stdio.h>
#include <algorithm>
#define MN 300000

int n,a[MN+5];

int test(int i){
	if(i<=1||i>=n) return 0;
	if(a[i]>a[i-1]&&a[i]>a[i+1]) return 1;
	if(a[i]<a[i-1]&&a[i]<a[i+1]) return 1;
	return 0;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==1){
		puts("0");
		return;
	}
	int ans = 0;
	int rans = 0x7fffffff;
	for(int i=2;i<=n-1;i++){
		ans += test(i);
	}
	for(int i=1;i<=n-1;i++){
		int tans = ans;
		tans -= test(i-1);
		tans -= test(i);
		tans -= test(i+1);
		int t = a[i];
		a[i] = a[i+1];
		tans += test(i-1);
		tans += test(i);
		tans += test(i+1);
		a[i] = t;
		rans = std::min(rans,tans);
	}
	for(int i=2;i<=n;i++){
		int tans = ans;
		tans -= test(i-1);
		tans -= test(i);
		tans -= test(i+1);
		int t = a[i];
		a[i] = a[i-1];
		tans += test(i-1);
		tans += test(i);
		tans += test(i+1);
		a[i] = t;
		rans = std::min(rans,tans);
	}
	printf("%d\n",rans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}