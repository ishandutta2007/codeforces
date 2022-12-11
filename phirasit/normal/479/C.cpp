#include <stdio.h>
#include <algorithm>

#define N 5010
#define A first
#define B second

using namespace std;

typedef pair<int, int> pii;

pii arr[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d%d", &arr[i].A, &arr[i].B);
	}
	sort(arr, arr+n);
	int mx = 0;
	for(int i = 0;i < n;i++) {
		if(arr[i].B >= mx) {
			mx = arr[i].B;
		}else {
			mx = arr[i].A;
		}
	}
	printf("%d\n", mx);
	return 0;
}