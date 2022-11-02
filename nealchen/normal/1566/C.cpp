#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
char s[100001], t[100001];
void work() {
	int n, ans=0;
	scanf("%d%s%s", &n, s, t);
	std::vector<int> a(n);
	for(int i=0; i<n; ++i) a[i]=(s[i]-'0')+(t[i]-'0');
	int status=0;
	for(int i=0; i<n; ++i) {
		if(a[i]==0) {
			if(status==0) {
				status=1;
			} else if(status==1) {
				++ans;
			} else {
				ans+=2;
				status=0;
			}
		} else if(a[i]==1) {
			ans+=(status==1)+2;
			status=0;
		} else {
			if(status==0) {
				status=2;
			} else if(status==1) {
				ans+=2;
				status=0;
			}
		}
	}
	ans+=(status==1);
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) work();
	return 0;
}