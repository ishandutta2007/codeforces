#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

#define cs(x) (int)x.size()
#define ll long long
#define ld long double
#define mp make_pair

using namespace std;

const ll mod = 175781251;

const ll INF = 1e12;

int main() {
	//iostream::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	//freopen("kthpath.in", "r", stdin);
	int n;
	cin >> n;
	vector<pair<int, int> > arr(1000001);
	int q = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a] = mp(arr[a].first + 1, q--);
	}
	cout << max_element(arr.begin(), arr.end()) - arr.begin() << endl;
	return 0;
}