#include <stdio.h>
#include <set>
#include <vector>

#define N 100010

using namespace std;

int arr[N];
int n, l, x, y;

bool fx = false, fy = false;
vector<int> vx, vy;

int main() {
	scanf("%d%d%d%d", &n, &l, &x, &y);
	set<int> S;
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
		S.insert(arr[i]);
		if(S.count(arr[i] - x)) fx = true;
		if(S.count(arr[i] - y)) fy = true;
	}
	if(fx && fy) {
		printf("0\n");
	}else if(fy) {
		printf("1\n%d\n", x);
	}else if(fx) {
		printf("1\n%d\n", y);
	}else {
		bool found = false;
		int id;
		for(int i = 0;i < n;i++) {
			if(arr[i] + x <= l && (S.count(arr[i] + x - y) || S.count(arr[i] + x + y))) {
				found = true;
				id = arr[i] + x;
				break;
			}else if(arr[i] - x >= 0 && (S.count(arr[i] - x - y) || S.count(arr[i] - x + y))) {
				found = true;
				id = arr[i] - x;
				break;
			}
		}
		if(found) {
			printf("1\n%d\n", id);
		}else {
			printf("2\n%d %d\n", x, y);
		}
	}
	return 0;
}