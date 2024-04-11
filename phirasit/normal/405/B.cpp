#include <stdio.h>

#define N 3010

char str[N];
int lf[N], rg[N];
int n;

int main() {
	scanf("%d%s", &n, str);
	bool active = false;
	for(int i = 0;i < n;i++) {
		if(str[i] == 'R') {
			active = true;
			lf[i] = 0;
			continue;
		}else if(str[i] == 'L') {
			active = false;
		}
		if(active) {
			lf[i] = lf[i-1] + 1; 
		}else {
			lf[i] = -1;
		}
	}
	active = false;
	for(int i = n-1;i >= 0;i--) {
		if(str[i] == 'L') {
			active = true;
			rg[i] = 0;
			continue;
		}else if(str[i] == 'R') {
			active = false;
		}
		if(active) {
			rg[i] = rg[i+1] + 1; 
		}else {
			rg[i] = -1;
		}
	}
	int ans = 0;
	for(int i = 0;i < n;i++) {
		if(lf[i] == rg[i]) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}