#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int ra = 0;
	int ma1 = -100000000;
	int mi1 = 100000000;
	int ma2 = -100000000;
	int mi2 = 100000000;
	for (int i = 0; i < n; ++i) {
		int c; cin >> c;
		int d; cin >> d;
		if (d == 2) {
			mi2 = min(mi2, ra);
			ma2 = max(ma2, ra);
		} else {
			mi1 = min(mi1, ra);
			ma1 = max(ma1, ra);
		}
		ra += c;
	}
	if (ma2 == -100000000) {
		cout << "Infinity";
	} else if(ma2 >= mi1) {
		cout << "Impossible";
	}else {
		cout << 1899 - ma2 + ra;
	}
}