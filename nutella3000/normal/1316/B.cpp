#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
 
using namespace std;
const int inf = 1e9 + 7;
string ans = "ajsdkas";
int ans_k = -1;
int n;

bool check(string new_ans) {
	if (ans == "ajsdkas") return true;
	for(int i = 0;i < n;i++) {
		if (new_ans[i] < ans[i]) return true;
		if (new_ans[i] > ans[i]) return false;
	}
	return false;
} 

void update(string new_ans, int num) {
	if (check(new_ans)) {
		ans = new_ans;
		ans_k = num;
	}
}

void solve() {
	string s;
	cin >> n >> s;
	ans = "ajsdkas";

	for(int k = 1;k <= n;k++) {
		string temp = "";
		for(int q = k - 1;q < n;q++) temp += s[q];

		if ((n - k + 1) % 2 == 0) {
			for(int q = 0;q < k - 1;q++) temp += s[q];
		}else for(int q = k - 2;q >= 0;q--) temp += s[q];

		//cout << k << " " << temp << '\n';

		update(temp, k);
	}

	cout << ans << '\n' << ans_k << '\n';


}






int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}