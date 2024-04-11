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
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, k, m, temp, ans = 0;

int main() {
	fast;
	cin >> n >> k;
	for (int x = 0; x < k; x++) {
		cin >> m >> temp;
		if (temp != 1) {
			ans += m - 1;
			while (--m > 0) cin >> temp;
		}
		else {
			vector<int> temp2;
			temp2.push_back(1);
			for (int i = 0; i < m - 1; i++) cin >> temp, temp2.push_back(temp);
			int j = 1;
			while (j < temp2.size() && temp2[j] == temp2[j - 1] + 1)
				j++;
			ans += m - j;
		}
	}
	cout << 2 * ans + k - 1 << endl;
}