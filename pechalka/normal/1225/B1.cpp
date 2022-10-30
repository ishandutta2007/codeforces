#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>
#include <string>

using namespace std;

int cnt[1000000];
int col[1000000];

int main(){
	int t;
	cin >> t;
	for (int query = 1; query <= t; ++query) {
		int n, k, d;
		cin >> n >> k >> d;
		vector<int> A(n);
		for (int i = 0; i < n; ++i){
			cin >> A[i];
			--A[i];
		}
		int nowcnt = 0;
		for (int i = 0; i < d; ++i){
			if (col[A[i]] < query){
				col[A[i]] = query;
				cnt[A[i]] = 1;
				++nowcnt;
			}
			else {
				++cnt[A[i]];
			}
		}
		int ans = nowcnt;
		for (int i = d; i < n; ++i){
			if (cnt[A[i - d]] == 1) {
				--cnt[A[i - d]];
				--nowcnt;
			}
			else
				--cnt[A[i - d]];
			if (col[A[i]] < query){
				col[A[i]] = query;
				cnt[A[i]] = 1;
			}
			else
				++cnt[A[i]];
			if (cnt[A[i]] == 1)
				++nowcnt;
			ans = min(ans, nowcnt);
		}
		cout << ans << '\n';
	}
	return 0;
}