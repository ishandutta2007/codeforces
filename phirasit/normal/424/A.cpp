#include <stdio.h>
#include <algorithm>

#define N 310

using namespace std;

char str[N];
int cnt = 0;
int n;

int main() {
	scanf("%d%s",&n,str);
	for(int i=0;i<n;i++) {
		cnt += (str[i] == 'x');
	}
	if(cnt <= n - cnt ) {
		printf("%d\n",(n-cnt-cnt)/2);
		int j = (n-cnt-cnt)/2;
		for(int i=0;i<n;i++) {
			if(str[i] == 'X') {
				if(j) {
					printf("x");
					j--;
				}else {
					printf("X");
				}
			}else {
				printf("x");
			}
		}
	}else {
		printf("%d\n",(cnt-n+cnt)/2);
		int j = (cnt-n+cnt)/2;
		for(int i=0;i<n;i++) {
			if(str[i] == 'x') {
				if(j) {
					printf("X");
					j--;
				}else {
					printf("x");
				}
			}else {
				printf("X");
			}
		}
	}
	printf("\n");
	return 0;
}