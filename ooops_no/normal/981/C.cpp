#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int l, r;
		cin >> l >> r;
		v[r]++;
		v[l]++;
	}
	vector<int> vc;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i]==1) {
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] == 1 && cnt == 2 || v[i] == cnt) {
			cout << "Yes" << endl;
			if (v[i] == 1) {
				cout << 1 << "\n";
			}
			else {
				cout << cnt << "\n";
			}
			for (int j = 1; j <= n; j++) {
				if (v[j] == 1 && j!=i) {
					cout << i << " " << j << endl;
				}
			}
			return 0;
		}
	}
	cout << "No";
}