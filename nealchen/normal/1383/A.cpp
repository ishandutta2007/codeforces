#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
const int N=1e5+5;
int n;
char a[N], b[N];
bool trans[20][20];
void work() {
	scanf("%d%s%s", &n, a, b);
	memset(trans, 0, sizeof(trans));
	for(int i=0; i<n; ++i) {
		if(a[i]>b[i]) {
			puts("-1");
			return;
		}
		if(a[i]<b[i]) trans[a[i]-'a'][b[i]-'a']=true;
	}
	int ans=0;
	for(int i=0; i<20; ++i) {
		for(int j=i+1; j<20; ++j) {
			for(int k=j+1; k<20; ++k) {
				if(trans[i][j] && trans[i][k]) {
					trans[j][k]=true;
					trans[i][k]=false;
				}
			}
		}
	}
	for(int i=0; i<20; ++i) {
		for(int j=0; j<20; ++j) ans+=trans[i][j];
	}
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) work();
	return 0;
}