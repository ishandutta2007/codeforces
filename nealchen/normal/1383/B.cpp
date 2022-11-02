#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
const int N=1e5+5;
int a[N];
void work() {
	int n, tot=0;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) {
		scanf("%d", a+i);
		tot^=a[i];
	}
	if(tot==0) {
		puts("DRAW");
		return;
	}
	tot=31^__builtin_clz(tot);
	int cnt[2]={};
	for(int i=1; i<=n; ++i) ++cnt[a[i]>>tot&1];
	puts(cnt[1]%4==1 || cnt[0]%2==1 ? "WIN" : "LOSE");
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) work();
	return 0;
}