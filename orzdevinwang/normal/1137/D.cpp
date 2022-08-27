#include<bits/stdc++.h>
using namespace std;
int n;
char s[12][12];
void init() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
}
int main() {
	while(1) {
		printf("next 0 1\n");
		fflush(stdout);
		init();
		printf("next 0\n");
		fflush(stdout);
		init();
		if(n == 2) break;
	}
	while(1) {
		printf("next 0 1 2 3 4 5 6 7 8 9\n");
		fflush(stdout);
		init();
		if(n == 1) break;
	}
	printf("done\n");
	fflush(stdout);
	return 0;
}