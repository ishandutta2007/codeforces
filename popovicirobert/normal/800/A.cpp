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
   	int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    double p;
    cin >> n >> p;
    vector<double> a(n), b(n);
    double sa = 0;
    for(i = 0; i < n; i++) {
    	cin >> a[i] >> b[i];
    	sa += a[i];
    }

   	if(sa <= p) {
   		cout << -1;
   		return 0;
   	}

   	auto get = [&](double t) {
   		double need = 0;
   		for(int i = 0; i < n; i++) {
   			need += max(0.0, t * a[i] - b[i]) / p;
   			need = min(need, 1e18);
   		}
   		return need;
   	};

   	double l = 0, r = 1e13;
   	for(i = 0; i < 100; i++) {
   		double mid = (l + r) * 0.5;
   		if(get(mid) < mid) {
   			l = mid;
   		}
   		else {
   			r = mid;
   		}
   	}

   	cout << fixed << setprecision(20) << 0.5 * (l + r);

    return 0;
}