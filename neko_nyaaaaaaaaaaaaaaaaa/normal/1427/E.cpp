#include <bits/stdc++.h>
using namespace std;

#define int long long

stringstream ss;
int sz_move;

string gs;
int cnt;

struct xor_basis{
	int d, sz;
	vector<long long> basis;

	xor_basis(int d) {
		this->d = d;
		sz = 0;
		basis.resize(d);
	}

	bool add(long long mask) {
		gs = ""; cnt = 0;
		for (int i = 0; i < d; i++) {
			if (mask & (1LL << i)) {
				if (!basis[i]) {
					basis[i] = mask; sz++;
					return 1;
				}
				gs += to_string(mask) + " ^ " + to_string(basis[i]) + "\n"; cnt++;
				mask ^= basis[i];
			}
		}
		return 0;
	}
} bs(40);

bool can_construct(long long val) {
	//cerr << "constructing " << val << '\n';
	long long ans = 0;
	for (int i = 0; i < 40; i++) {
		if ((val & (1LL << i)) != (ans & (1LL << i))) {
			if (bs.basis[i] == 0) return 0;
			ans ^= bs.basis[i];
		}
	}
	return ans == val;
}

void construct(long long val) {
	long long ans = 0;
	for (int i = 0; i < 40; i++) {
		if ((val & (1LL << i)) != (ans & (1LL << i))) {
			if (ans != 0) {
				ss << ans << " ^ " << bs.basis[i] << '\n';
				sz_move++;
			}
			ans ^= bs.basis[i];
		}
	}
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int RAND(int lo, int hi) {
	return uniform_int_distribution<int>(lo, hi)(rng);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int x; cin >> x;
	set<long long> s; s.insert(x);
	vector<long long> v; v.push_back(x);

	long long MX = (1LL << 40) - 1;
	for (long long i: v) bs.add(i);

	while (!can_construct(1)) {
		//cerr << "next move pick\n";
		long long A, B;
		while (1) {
			int i = RAND(0, v.size() - 1);
			int j = RAND(0, v.size() - 1);

			//cerr << "picking " << i << ' ' << j << endl;

			if (v[i]+v[j] > MX);
			if (s.find(v[i]+v[j]) != s.end()) continue;
			if (bs.add(v[i]+v[j])) {
				A = v[i], B = v[j];
				break;
			}
		}
		s.insert(A+B);
		v.push_back(A+B);
		//cerr << "New add\n";
		ss << A << " + " << B << '\n'; sz_move++;
		ss << gs; sz_move += cnt;
	}
	construct(1);

	cout << sz_move << '\n' << ss.str();

	return 0;
}