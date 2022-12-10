//sobskdrbhvk...
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

#define smin(x, y) x = min(x, y)
#define PB push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define L first
#define R second

const int maxn = 8;

void print(pii x) {
	cout << char('a' + x.L) << x.R + 1 << ' ';
}

int main() {
	vector<pii> vec;
	int n;
	cin >> n;
	n++;
	for (int i = 0; i < 7; i++) {
		int st = (i & 1) ? 6 : 0;
		int en = 6 - st;
		int d = (i & 1) ? -1 : +1;
		while (st != en) {
			vec.PB(MP(i, st));
			st += d;
		}
		vec.PB(MP(i, st));
	}
	vec.pop_back();
	if (n <= 50) {
		auto pos = vec[n - 3];
		for (int i = 0; i < n - 2; i++)
			print(vec[i]);
		print(MP(7, pos.R));
		print(MP(7, 7));
	}
	else {
		for (auto pos : vec)
			print(pos);
		if (n <= 57) {
			auto pos = vec.back();
			n -= 50;
			print(MP(6, 6));
			pos.L = 7;
			pos.R = 6;
			print(pos);
			while (pos.R > 0 and n > 1) {
				pos.R--;
				print(pos);
				n--;
			}
			print(MP(7, 7));
		}	
		else {
			auto pos = vec.back();
			pos.L = 7;
			while (pos.R >= 0) {
				print(pos);
				pos.R--;
			}
			print(MP(7, 6));
			print(MP(6, 6));
			pos = MP(6, 7);
			print(pos);
			n -= 57;
			while (pos.L > 0 and n > 1) {
				pos.L--;
				print(pos);
				n--;
			}
			print(MP(7, 7));
		}
	}
	return 0;
}