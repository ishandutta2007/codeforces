#include <stdio.h>
#include <algorithm>

#define N 100010

using namespace std;

typedef pair<int, int> pii;

pii arr[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + n);
	bool found = false;
	for(int i = n-2;i >= 0;i--) {
		if(arr[i].second > arr[i+1].second) {
			found = true;
		}
	}
	if(found) {
		printf("Happy Alex\n");
	}else {
		printf("Poor Alex\n");
	}
	return 0;
}