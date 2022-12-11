#include <stdio.h>
#include <vector>

#define N 100010

using namespace std;

int arr[N];
int n;

vector<int> P;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
	}
	arr[n+1] = 0;
	int fs;
	for(int i = 1;i <= n;i++) {
		if(arr[i] > arr[i+1]) {
			fs = i;
			break;
		}
	}
	int ls = fs;
	while(ls+1 <= n && arr[ls+1] <= arr[ls]) {
		ls++;
	}
	bool err = false;
	if(ls+1 <= n && arr[fs] > arr[ls+1]) { 
		err = true;
	}
	if(fs-1 >= 1 && arr[ls] < arr[fs-1]) {
		err = true;
	}
	for(int i = ls;i < n;i++) {
		if(arr[i] > arr[i+1]) {
			err = true;
		}
	}
	if(err) {
		printf("no\n");
	}else {
		printf("yes\n");
		printf("%d %d\n", fs, ls);
	}
	return 0;
}