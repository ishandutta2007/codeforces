#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {
	if (a > b) {a = b; return true;} return false;
}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {
	if (a < b) {a = b; return true;} return false;
}
const int N = 1e5 + 5; 
const int oo = 1e9;

int cnt[N];

void solve() {
	string s; cin >> s;

	for (int i = 'a'; i <= 'z'; i++)
		cnt[i] = 0;

	for (char c : s)
		cnt[c]++;

	for (char i = 'a'; i <= 'z'; i++) if (cnt[i] == 1) {
		cout << i;
		cnt[i]--;
		for (char j = 'a'; j <= 'z'; j++)
			while (cnt[j]--)
				cout << j;

		cout << "\n";
		return;
	}

	int cntchar = 0;
	for (int i = 'a'; i <= 'z'; i++)
		cntchar += (cnt[i] > 0);

	if (cntchar == 1) 
		return (void) (cout << s << "\n");

	int n = s.size();
	for (char i = 'a'; i <= 'z'; i++) if (cnt[i]) {
		cout << i;
		cnt[i]--;
		int tot = 0;
		for (char j = i + 1; j <= 'z'; j++)
			tot += cnt[j];

		if (tot >= cnt[i] - 1) {
			cout << i;
			cnt[i]--;
			for (char j = i + 1; j <= 'z'; j++) {
				while (cnt[i] > 0 && cnt[j] > 0) {
					cnt[i]--, cnt[j]--;
					cout << j << i;
				}
			}
		} else {
			for (char j = i + 1; j <= 'z'; j++) if (cnt[j] > 0) {
				if (cntchar > 2) {
					cnt[j]--;
					cout << j;
					while (cnt[i] > 0) {
						cnt[i]--;
						cout << i;
					}
					j++;

					while (cnt[j] == 0)
						j++;

					cnt[j]--;
					cout << j;
				} else {
					while (cnt[j] > 0) {
						cout << j;
						cnt[j]--;
					}
				}
				break;
			}
		}

		for (char j = 'a'; j <= 'z'; j++) {
			while (cnt[j] > 0) {
				cnt[j]--;
				cout << j;
			}
		}

		break;
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}