#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

bool exist = false;
int n, k;
string s[5000], p[5000];

vector<int> comp(string &a, string &b) {
	vector<int> rtn;
	for (int i = 0; i < k; i++)
		if (a[i] != b[i]) rtn.push_back(i);
	return rtn;
}

bool check(string &a) {
	for (int i = 0; i < n; i++) {
		if (comp(a, s[i]).size() > 2) return false;
		if (comp(a, s[i]).size() == 0 && !exist) return false;
	}
	return true;
}

int main() {
	fast;
	string xd = "aba";
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		p[i] = s[i];
		sort(p[i].begin(), p[i].end());
	}
	for (int i = 1; i < n; i++)
		if (p[0].compare(p[i])) finish(-1);

	for (int i = 1; i < k; i++) if (p[0][i] == p[0][i - 1]) exist = true;

	int at[2];
	vector<int> worst, temp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			temp = comp(s[i], s[j]);
			if (temp.size() > worst.size()) worst = temp, at[0] = i, at[1] = j;
		}
	}
	//	cout << at[0] << " " << at[1] << endl;
	//	for (auto &i : worst) cout << i << endl;
	if (worst.size() == 0) {
		if (exist) finish(s[0]);
		swap(s[0][0], s[0][1]);
		finish(s[0]);
	}
	if (worst.size() > 4) finish(-1);

	string perm = "";
	for (auto &i : worst) perm.push_back(s[at[0]][i]);
	sort(perm.begin(), perm.end());

	string sus = s[at[0]];

	int lim = 1;
	for (int i = 2; i <= worst.size(); i++) lim *= i;

	for (int i = 0; i < lim; i++) {
		for (int j = 0; j < worst.size(); j++)
			sus[worst[j]] = perm[j];
		//		cout << "sus " << sus << endl;
		if (check(sus)) finish(sus);
		next_permutation(perm.begin(), perm.end());
	}
	finish(-1);
}