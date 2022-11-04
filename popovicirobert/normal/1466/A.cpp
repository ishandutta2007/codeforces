#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		vector<int> x(n);
		for(i = 0; i < n; i++) {
			cin >> x[i];
		}

		auto getArea = [&](int x1, int y1, int x2, int y2, int x3, int y3) -> double {
			return 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
		};

		unordered_set<double> mst;
		for(i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++)
				mst.insert(getArea(0, 1, x[i], 0, x[j], 0));
		}

		cout << mst.size() << "\n";
	}

	
    return 0;
}