#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;



int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> t;

	vector<multiset<int>> mst(30);
	vector<ll> sum(30);

	int cnt = 0;

	while(t--) {
		char type;
		int x;
		cin >> type >> x;

		auto msb = [&](int x) {
			int bit = 30;
			while(((1 << bit) & x) == 0) {
				bit--;
			}
			return bit;
		};

		int bit = msb(x);
		if(type == '+') {
			mst[bit].insert(x);
			sum[bit] += x;
			cnt++;
		}
		else {
			mst[bit].erase(mst[bit].find(x));
			sum[bit] -= x;
			cnt--;
		}

		int ans = 0;
		ll s = 0;
		for(i = 0; i < 30; i++) {
			if(mst[i].size()) {
				if(2LL * s < *mst[i].begin()) {
					ans++;
				}
			}
			if(t == 7)
				cerr << s << " " << i << " " << ans << "\n";
			s += sum[i];
		}
		cout << cnt - ans << '\n';
	}

    return 0;
}