#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 100010;

int arr[N];
int n;

int main() {
	scanf("%d", &n);
	int gcd = 0;
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);	
		gcd = __gcd(gcd, arr[i]);
	}
	for(int i = 0;i < n;i++) {
		int val = arr[i];
		val /= gcd;
		while(val % 2 == 0) val /= 2;
		while(val % 3 == 0) val /= 3;
		if(val > 1) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}