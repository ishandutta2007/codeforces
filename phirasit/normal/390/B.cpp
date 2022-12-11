#include <stdio.h>
#include <algorithm>

#define N 100010

using namespace std;

int arr[N];
int n;

long long joy = 0;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	for(int i = 0;i < n;i++) {
		int b;
		scanf("%d", &b);
		int g = b/2;
		int p = b-g;
		if(0 < g && p <= arr[i]) {
			joy += (long long) g * p;
		}else {
			joy--;
		}
	}
	printf("%I64d\n", joy);
	return 0;
}