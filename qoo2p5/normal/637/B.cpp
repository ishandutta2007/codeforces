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
	set<pair<int, string> > arr;
	unordered_map<string, int> curnum;
	int n;
	cin >> n;
	int q = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (curnum.count(s))
			arr.erase(mp(curnum[s], s));
		curnum[s] = q++;
		arr.insert(mp(curnum[s], s));
	}
	for (auto it = arr.rbegin(); it != arr.rend(); it++)
		cout << it->second << endl;
	return 0;
}