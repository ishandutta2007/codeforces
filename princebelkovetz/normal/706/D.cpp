#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int bits = 30;
struct node {
	int bb[2];
	int num = 0;
};
node nul = { {0, 0}, 0 };
vector <node> bor;
void add(int v) {
	int cur = 0;
	for (int i = bits; i >= 0; --i) {
		int need = (v >> i) & 1;
		if (bor[cur].bb[need]) {
			cur = bor[cur].bb[need];
		}
		else {
			bor.push_back(nul);
			bor[cur].bb[need] = bor.size() - 1;
			cur = bor.size() - 1;
		}
		bor[cur].num++;
	}
}
void pop(int v) {
	int cur = 0;
	for (int i = bits; i >= 0; --i) {
		int need = (v >> i) & 1;
		cur = bor[cur].bb[need];
		bor[cur].num--;
	}
}
void getans(int v) {
	int cur = 0, ans = 0;
	for (int i = bits; i >= 0; --i) {
		int need = (v >> i) & 1;
		need ^= 1;
		if (bor[cur].bb[need] and bor[bor[cur].bb[need]].num) {
			cur = bor[cur].bb[need];
			ans += (1 << i);
		}
		else {
			cur = bor[cur].bb[(1 ^ need)];
		}
	}
	cout << max(v, ans) << '\n';
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int q, x; cin >> q;
	string s;
	bor.resize(1);
	while (q --> 0) {
		cin >> s;
		cin >> x;
		if (s == "+") add(x);
		if (s == "-") pop(x); 
		if (s == "?") getans(x);
		//for (int i = 0; i < bor.size(); ++i) {
			//cout << i << " : ";
			//cout << bor[i].bb[0] << ' ' << bor[i].bb[1] << ' ' << bor[i].num << '\n';
		//}
	}
}