#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> n;

	vector<int> arr(n);
	for(i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](const int& a, const int& b) {
		if(arr[a] == arr[b]) return a < b;
		return arr[a] < arr[b];
	});

	vector<int> pos(n);
	for(i = 0; i < n; i++) {
		arr[ord[i]] = i;
		pos[i] = ord[i];
	}

	vector<pair<int, int>> sol;
	for(int j = n - 1; j >= 0; j--) {
		for(i = arr[j] + 1; i <= j; i++) {
			//cerr << i << " " << arr[j] << "\n";
			sol.push_back({pos[i], j});
			swap(pos[arr[j]], pos[i]);
			swap(arr[j], arr[pos[arr[j]]]);
		}
	}

	cout << sol.size() << "\n";
	for(auto it : sol) {
		cout << it.first + 1 << " " << it.second + 1 << "\n";
	}


    return 0;
}