#include <stdio.h>

#define N 20

char str[N];
int p = 0, q = 0;
int cnt = 0;

double dfs(int i, int s) {
	if(i >= cnt) {
		return (s == p-q ? 1.0 : 0.0);
	}
	return (dfs(i+1, s+1) + dfs(i+1, s-1)) / 2;
}
int main() {
	scanf("%s", str);
	for(int i = 0;str[i];i++) {
		if(str[i] == '+') {
			p++;
		}else {
			p--;
		}
	}
	scanf("%s", str);
	for(int i = 0;str[i];i++) {
		if(str[i] == '+') {
			q++;
		}else if(str[i] == '-') {
			q--;
		}else {
			cnt++;
		}
	}
	printf("%.10lf\n", dfs(0, 0));	
	return 0;
}