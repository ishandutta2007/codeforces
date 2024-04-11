#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

string s1, s2, s3;
vector<int> a(2002, 0), b(2002, 0);
unordered_set<int> h[2002];

int main() {
	fast;
	cin >> s1 >> s2 >> s3;
	int temp = s1.find(s2);
	while (temp != -1) {
		a[temp] = 1;
		temp = s1.find(s2, temp + 1);
	}
	temp = s1.find(s3);
	while (temp != -1) {
		b[temp + s3.size() - 1] = 1;
		temp = s1.find(s3, temp + 1);
	}

//	for (int i = 0; i < s1.size(); i++) cout << a[i] << " "; cout << endl;
//	for (int i = 0; i < s1.size(); i++) cout << b[i] << " "; cout << endl;

	for (int i = 0, lim = max(s2.size(), s3.size()); i + lim - 1 < s1.size(); i++) {
		if (a[i]) {
			int len = 0;
			ll val = 0;
			for (int j = i; j < i + lim; j++)
				val = (val * hs + s1[j]) % md, len++;
			if (b[i + lim - 1]) h[len].insert(val);
			for (int j = i + lim; j < s1.size(); j++) {
				val = (val * hs + s1[j]) % md, len++;
				if (b[j]) h[len].insert(val);
			}
		}
	}

	int tot = 0;
	for (int i = 0; i < 2002; i++)
		tot += h[i].size();
	cout << tot << endl;
}