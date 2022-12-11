#include <stdio.h>
#include <algorithm>

#define N 100010

using namespace std;

int arr[N];
int n;

int main() {
	scanf("%d",&n);
	for(int i = 1;i < n;i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr + 1, arr + n);
	bool found = false;
	for(int i = 1;i < n;i++) {
		if(arr[i] != i) {
			printf("%d\n",i);
			found = true;
			break;
		}
	}
	if(found == false) {
		printf("%d\n",n);
	}
	return 0;
}