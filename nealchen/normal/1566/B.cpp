#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
char s[100001];
void work() {
	scanf("%s", s);
	int n=strlen(s);
	bool vis[2]={};
	for(int i=0; i<n; ++i) vis[s[i]-='0']=true;
	if(!vis[0]) {
		puts("0");
	} else if(!vis[1]) {
		puts("1");
	} else {
		int i=0, j=n;
		while(s[i]) ++i;
		while(s[j-1]) --j;
		for(int k=i; k<j; ++k) {
			if(s[k]) {
				puts("2");
				return;
			}
		}
		puts("1");
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) work();
	return 0;
}