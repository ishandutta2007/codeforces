#include <stdio.h>
#include <algorithm>

#define MX_N 100010

using namespace std;

int arr[10];
int opt[10];
int ans[MX_N][5];
int n;

int main() {
	int i,j;
	scanf("%d",&n);
	bool valid = true;
	for(i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		arr[a]++;
		if(a == 7 || a == 5)
			valid = false;
	}
	// 1 2 4 
	// 1 3 6
	// 1 2 6
	n /= 3;
	for(i=0;i<n;i++) {
		if(arr[1]-- == 0) valid = false;
		ans[i][0] = 1;
		if(arr[2]-- > 0) {
			ans[i][1] = 2;
			if(arr[4]-- > 0) {
				ans[i][2] = 4;
			}else if(arr[6]-- > 0) {
				ans[i][2] = 6;
			}else {
				valid = false;
			}
		}else if(arr[3]-- > 0) {
			ans[i][1] = 3;
			if(arr[6]-- > 0) {
				ans[i][2] = 6;
			}else {
				valid = false;
			}
		}else {
			valid = false;
		}
	}
	if(valid == true) {
		for(i=0;i<n;i++) {
			printf("%d %d %d",ans[i][0],ans[i][1],ans[i][2]);
			printf("\n");
		}
	}else {
		printf("-1\n");
	}
	return 0;
}