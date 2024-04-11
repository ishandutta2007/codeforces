#include <stdio.h>
#include <algorithm>
#include <vector>

#define N 3010

using namespace std;

int arr[N];
int n;

vector< pair<int, int> > ans;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	for(int i = 0;i < n-1;i++) {
		int mn = i;
		for(int j = i+1;j < n;j++) {
			if(arr[j] < arr[mn]) {
				mn = j;
			}
		}
		if(mn != i) {
			ans.push_back(pair<int, int>(i, mn));
			swap(arr[i], arr[mn]);
		}
	}
	printf("%d\n", ans.size());
	for(int i = 0;i < (int) ans.size();i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}