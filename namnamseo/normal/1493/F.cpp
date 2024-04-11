#include <iostream>
using namespace std;

bool is_prime(int n) {
	for (int i=2; i*i<=n; ++i) if (n%i == 0) return false;
	return true;
}

bool ask(int ns, int ms, int x, int y, int xx, int yy) {
	cout << "? " << ns << ' ' << ms << ' '
		<< x << ' ' << y << ' '
		<< xx << ' ' << yy << '\n' << flush;

	int ans; cin >> ans;
	return ans == 1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;

	int cr = 1, cc = 1;
	int wr = n, wc = m;

	for (int p=2; p<=1000; ++p) if (is_prime(p)) {
		while (wr%p == 0) {
			bool ok = 1;

			int uni = wr/p;
			if (p == 2) {
				for (int i=1; i<p; ++i) {
					if (ask(uni, wc,
							1+(i-1)*uni, 1,
							1+i*uni, 1) == false) {
						ok = 0; break;
					}
				}
			} else {
				int h = p/2;
				ok = ask(uni*h, wc,
					1, 1,
					1+uni*h, 1) &&
					ask(uni*h, wc,
					1, 1,
					1+uni*(h+1), 1);
			}

			if (!ok) break;
			cr *= p;
			wr /= p;
		}

		while (wc%p == 0) {
			bool ok = 1;
			int uni = wc/p;

			if (p == 2) {
				for (int i=1; i<p; ++i) {
					if (ask(wr, uni,
							1, 1+(i-1)*uni,
							1, 1+i*uni) == false) {
						ok = 0; break;
					}
				}
			} else {
				int h = p/2;
				ok = ask(wr, uni*h,
					1, 1,
					1, 1+uni*h) &&
					ask(wr, uni*h,
					1, 1,
					1, 1+uni*(h+1));
			}
			if (!ok) break;
			cc *= p;
			wc /= p;
		}
	}

	int dcr = 0, dcc = 0;
	for (int d=1; d<=cr; ++d) if (cr%d == 0) ++dcr;
	for (int d=1; d<=cc; ++d) if (cc%d == 0) ++dcc;

	cout << "! " << (dcr * 1ll * dcc) << '\n' << flush;

	return 0;
}