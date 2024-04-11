#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	std::vector<int> v(n);
	vector<string> a(n); for (int o = 0; o < n; o++) { cin >> v[o] >> a[o]; }
	int dis = 0;
	bool b = true;
	for (int i = 0; i < n; ++i) {
		if (dis == 0 && a[i] != "South") {
			b = false;
		} else if(dis == 20000 && a[i] != "North") {
			b = false;
		}

		if (a[i] == "North") {
			dis -= v[i];
		} else if(a[i] == "South") {
			dis += v[i];
		}

		if (dis < 0 || dis > 20000) {

			b = false; 
		}
	}
	if (dis != 0) {
		b = false;
	} 
	if (b) cout << "YES";
	else cout << "NO";

}