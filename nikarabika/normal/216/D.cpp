//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//Man am A _____ & a pair of Izzz wayTn' 230u :)

#define PB push_back

const int maxn = 1e3 + 10;
vector<int> v[maxn];
int n, ans;

void solve(vector<int> &v1, vector<int> &v2, vector<int> &v3){
	for(int i = 0; i + 1 < v2.size(); i++){
		int cnt1 = lower_bound(v1.begin(), v1.end(), v2[i + 1]) - upper_bound(v1.begin(), v1.end(), v2[i]);
		int cnt2 = lower_bound(v3.begin(), v3.end(), v2[i + 1]) - upper_bound(v3.begin(), v3.end(), v2[i]);
		ans += cnt1 != cnt2;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int cnt;
		cin >> cnt;
		for(int j = 0; j < cnt; j++){
			int val;
			cin >> val;
			v[i].PB(val);
		}
		sort(v[i].begin(), v[i].end());
	}
	for(int i = 0; i < n; i++)
		solve(v[i], v[(i + 1) % n], v[(i + 2) % n]);
	cout << ans << endl;
	return 0;
}