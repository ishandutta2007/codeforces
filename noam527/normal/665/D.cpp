#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
using namespace std;

vector<int> a, ans, sieve(2e6 + 3, 1);
int n;
bool neede = true, needo = true;

void makesieve() {
	for (int i = 2; i * i < sieve.size(); i++)
		if (sieve[i])
			for (int j = i * i; j < sieve.size(); j += i) sieve[j] = 0;
}

void done() {
	cout << ans.size() << endl;
	for (auto i : ans) cout << i << " "; cout << endl;
}

int main() {
	makesieve();
	fast;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1) {
		cout << 1 << endl << a[0] << endl;
		return 0;
	}
	sort(a.begin(), a.end());
	int i = 0;
	if (a[1] == 1) {
		while (i < n && a[i] == 1) ans.push_back(1), i++;
		for (; i < n; i++)
			if (sieve[a[i] + 1]) {
				ans.push_back(a[i]);
				done();
				return 0;
			}
		done();
		return 0;
	}
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
		if (sieve[a[i] + a[j]]) {
			ans.push_back(a[i]), ans.push_back(a[j]);
			done();
			return 0;
		}
	}
	ans.push_back(a[0]);
	done();
	return 0;
}