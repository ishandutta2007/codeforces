#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
const int N=1e6+5, P=1e9+7;
int f[N];
char s[N];
std::vector<int> seg;
int main() {
	scanf("%s", s);
	int n=strlen(s), n0=0;
	for(int i=0; i<n; ++i) {
		if(s[i]=='1') {
			seg.push_back(n0);
			n0=0;
		} else {
			++n0;
		}
	}
	if(seg.empty()) {
		printf("%d\n", n0);
		return 0;
	}
	int ht=(seg[0]+1)*(n0+1llu)%P, sum=0, g=1;
	for(int i=1; i<seg.size(); ++i) {
		for(int j=0; j<=seg[i]; ++j) {
			sum=(0u+sum+P-f[j]+g)%P;
			f[j]=g;
		}
		g=(sum+1)%P;
	}
	printf("%lld\n", 1llu*ht*g%P);
	return 0;
}