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
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("kthpath.in", "r", stdin);
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int curans = 6;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int q = 0;
			for (int k = 0; k < 6; k++) {
				if (arr[i][k] != arr[j][k])
					q++;
			}
			int need = q / 2 + q % 2;
			curans = min(curans, need - 1);
		}
	}
	cout << curans << endl;
	return 0;
}