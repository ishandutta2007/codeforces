#include <stdio.h>
#include <vector>

using namespace std;

vector<int> arr[5];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		int val;
		scanf("%d", &val);
		arr[val].push_back(i);
	}
	int mn = arr[1].size();
	for(int i = 1;i <= 3;i++) {
		mn = min(mn, (int)arr[i].size());
	}
	printf("%d\n", mn);
	for(int i = 0;i < mn;i++) {
		printf("%d %d %d\n", arr[1][i], arr[2][i], arr[3][i]);
	}
	return 0;
}