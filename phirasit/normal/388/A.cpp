#include <stdio.h>
#include <algorithm>

#define N 110

using namespace std;

int sz[N];
int arr[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	int piles = 0;
	for(int i = 0;i < n;i++) {
		bool found = false;
		int mn = -1;
		for(int j = 0;j < piles;j++) {
			if(arr[i] >= sz[j] && (mn == -1 || sz[j] < sz[mn])) {
				found = true;
				mn = j;
			}
		}
		if(found) {
			sz[mn]++;
		}else {
			sz[piles++] = 1;
		}
	}
	printf("%d\n", piles);
	return 0;
}