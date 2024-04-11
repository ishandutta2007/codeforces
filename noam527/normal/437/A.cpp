#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

string s[4];
int n[4];
vector<int> spe;

int main() {
	fast;
	for (int i = 0; i < 4; i++) cin >> s[i], n[i] = s[i].size() - 2;
	for (int i = 0; i < 4; i++) {
		bool g1 = true, g2 = true;
		for (int j = 0; j < 4; j++)
			if (i != j) {
				g1 = g1 && (2 * n[i] <= n[j]);
				g2 = g2 && (n[i] >= 2 * n[j]);
			}
		if (g1 || g2) spe.push_back(i);
	}
	if (spe.size() == 1) cout << char(spe[0] + 'A') << endl;
	else cout << 'C' << endl;
}