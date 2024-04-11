#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;
const int max_n = 1e5 + 1;
int n;
int nex[max_n];
int cnt[max_n];
int b[max_n];
int p[max_n];

void scan() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		cnt[i] = 1;
		nex[i] = i;
		cin >> p[i];
		b[i] = 0;
	}

	nex[n] = n;
	b[0] = 0;
	b[1] = n;
}

int get(int a) {
	int p = a;
	while(a != nex[a]) {
		a = nex[a];
	}
	while(p != a) {
		int t = nex[p];
		nex[p] = a;
		p = t;
	}

	return a;
}



void solve() {
	scan();

	vector<int> id(n);
	for(int i = 0;i < n;i++) id[i] = i;
	sort(id.begin(), id.end(), [](int v1, int v2){return p[v1] < p[v2];});

	bool bad = false;


	int m = 1;


	for(int i : id) {
		while(b[m] == 0) m--;

		int maximal = m;

		if (maximal != cnt[i]) {
			bad = true;
			break;
		}

		nex[i] = i + 1;

		int pr = get(i);

		//cout << i << " " << cnt[i] << " " << pr << endl;

		b[cnt[i]]--;

		//cout << "good" << endl;

		if (pr != n) {
			b[cnt[pr]]--;
			cnt[pr] += cnt[i];

			b[cnt[pr]]++;

			m = cnt[pr];
		}

		//cout << "bad" << endl;
	}


	if (bad) cout << "No" << '\n';
	else cout << "Yes" << '\n';

}




	
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);


   	int t;
   	cin >> t;
   	while(t--) {
   		solve();
   	}

}