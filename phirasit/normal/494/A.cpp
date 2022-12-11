#include <stdio.h>
#include <string.h>

#define N 100010

char str[N];
int ans[N], k = 0;
int l;

int main() {
	scanf("%s", str);
	l = strlen(str);
	int cnt = 0;
	int pos = -1;
	for(int i = 0;str[i];i++) {
		cnt += ((str[i] == '(') ? 1 : -1);
		if(str[i] == '#') {
			pos = i;
		}
		if(cnt < 0) {
			printf("-1\n");
			return 0;
		}
	}
	int last = 1 + cnt;
	cnt = 0;
	for(int i = 0;str[i];i++) {
		if(i == pos) {
			cnt -= last;
		}else {
			cnt += ((str[i] == '(') ? 1 : -1);
		}
		if(cnt < 0) {
			printf("-1\n");
			return 0;
		}	
	}
	for(int i = 0;str[i];i++) {
		if(str[i] == '#') {
			printf("%d\n", (i == pos ? last : 1));
		}
	}
	return 0;
}