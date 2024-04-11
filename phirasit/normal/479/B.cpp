#include <stdio.h>
#include <algorithm>
#include <vector>

#define N 110

using namespace std;

vector< pair<int, int> > ans;

int arr[N];
int n, k;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
	}
	for(int p = 0;p < k;p++) {
		int mx = 0, a, b;			
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				if(i == j) {
					continue;
				}
				int dif = arr[i] - arr[j];
				if(dif != 0 && dif > mx) {
					mx = dif;
					a = i;
					b = j;
				}
			}
		}
		if(mx != 0) {
			ans.push_back(pair<int, int>(a, b));
			arr[a]--;
			arr[b]++;
		}
	}
	int mx = 0, mn = (-1u/2);
	for(int i = 1;i <= n;i++) {
		if(arr[i] > mx) mx = arr[i];
		if(arr[i] < mn) mn = arr[i];
	}
	printf("%d %d\n", mx-mn, ans.size());
	for(int i = 0;i < ans.size();i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}