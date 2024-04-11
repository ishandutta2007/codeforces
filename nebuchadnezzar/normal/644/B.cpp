#include <bits/stdc++.h>
#define ff first
#define ss second
#define puba push_back
#define szof(_x) ((int) (_x).size())
#define bend(_x) (_x).begin(), (_x).end()
#define TASK_NAME ""           

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n, b;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &b);
	++b;

	set<tuple<ll, int, int>> now;
	vector<pii> inp;
	vector<ll> ans;
	ans.resize(n);

	for (int i = 0; i < n; ++i) {
	 	int t, d;
	 	scanf("%d%d", &t, &d);
	 	now.insert(make_tuple(t, 1, i));
	 	inp.puba({t, d});
	}

	queue<int> q;
	while (szof(now)) {
		int type, i;
		ll t;
		tie(t, type, i) = *now.begin();
		//cerr << t << " " << type << " " << i << endl;
		now.erase(now.begin());
	 	if (type == 0) {
	 		ans[i] = t;
	 	 	//cerr << szof(q) << endl;
	 	 	q.pop();
	 	 	if (szof(q)) {
	 	 		//cerr << "add " << q.front() << endl;
	 	 	    now.insert(make_tuple(t + inp[q.front()].ss, 0, q.front()));
	 	 	}
	 	} else {
	 	 	if (szof(q) < b) {
	 	 	 	q.push(i);
	 	 	 	if (szof(q) == 1) {
    	 	 	    now.insert(make_tuple(t + inp[q.front()].ss, 0, q.front()));
    	 	 	}
	 	 	} else {
	 	 	 	ans[i] = -1;
	 	 	}
	 	}
	}

	for (int i = 0; i < n; ++i) {
	 	cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}