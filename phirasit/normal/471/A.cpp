#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[10];

int main() {
	for(int i = 0;i < 6;i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + 6);
	for(int j = 0;j < 3;j++) {
		bool err = false;
		for(int i = j;i < j+4;i++) {
			if(arr[i] != arr[j]) {
				err = true;
			}
		}
		if(!err) {
			int a, b;
			if(j == 0) {
				a = arr[4];
				b = arr[5];
			}else if(j == 1) {
				a = arr[0];
				b = arr[5];
			}else if(j == 2) {
				a = arr[0];
				b = arr[1];
			}
			if(a != b) {
				printf("Bear\n");
			}else if(a == b) {
				printf("Elephant\n");
			}
			return 0;
		}
	}
	printf("Alien\n");
	return 0;
}