#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
using namespace std;

int ask(int l, int r) {
	cout << "? " << l + 1 << " " << r + 1 << endl;
	int n; cin >> n;
	return n;
}

void give(std::vector<int>& a) {
	cout << "! ";
	for (int i = 0; i < 6; ++i) cout << a[i] << " ";
	cout << endl;

}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	std::vector<int> a = {4 , 8, 15, 16, 23, 42};
	std::vector<int> an(4);
	for (int i = 0; i < 4; ++i) {
		an[i] = ask(i, i + 1);
	}
	std::vector<int> b(6, 0);
	do {
		bool f = true;
		for (int i = 0; i < 4; ++i) {
			if (a[i] * a[i + 1] != an[i]) {
				f = false;
				break;
			} 
		}
		if (f) break;
	} while(next_permutation(a.begin(), a.end()));
	b[5] = a[5];
	int jj = 0;
	if (a[5] != 23) {
		bool ok[4] = {};
		for (int i = 0; i < 4; ++i) {
			if (an[i] % 23 == 0) {
				ok[i] = true;
			} 
		}
		if (ok[0] && ok[1]) {
			b[jj = 1] = 23;
		} else if(ok[1] && ok[2]) {
			b[jj = 2] = 23;
		} else if(ok[2] && ok[3]) {
			b[jj = 3] = 23;
		} else if(ok[0]) {
			b[jj = 0] = 23;
		} else {
			b[jj = 4] = 23;
		}
	} else {
		bool ok[4] = {};
		for (int i = 0; i < 4; ++i) {
			if (an[i] % 15 == 0) {
				ok[i] = true;
			} 
		}
		if (ok[0] && ok[1]) {
			b[jj = 1] = 15;
		} else if(ok[1] && ok[2]) {
			b[jj = 2] = 15;
		} else if(ok[2] && ok[3]) {
			b[jj = 3] = 15;
		} else if(ok[0]) {
			b[jj = 0] = 15;
		} else {
			b[jj = 4] = 15;
		}
	}
	for (int i = jj + 1; i < 5; ++i) {
		b[i] = an[i - 1] / b[i - 1];
	}
	for (int i = jj - 1; i >= 0; --i) {
		b[i] = an[i] / b[i + 1];
	}
	give(b);
}