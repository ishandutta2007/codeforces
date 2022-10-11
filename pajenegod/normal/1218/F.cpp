#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pair2;
typedef pair<int, pair<int, int> > pair3;
typedef pair<int, pair<int, pair<int, int> > > pair4;
#define MAXN 200013
#define INF 1000000000000000000LL
#define MOD 1000000007LL
#define IINF 1000000000
#define mp make_pair
#define pb push_back
#define remove pop
#define all(x) x.begin(), x.end()

int n;
ll k;
ll a;
ll drinks[MAXN];
ll required[MAXN];

int main() {
	if (fopen("FILENAME.in", "r")) {
		freopen("FILENAME.in", "r", stdin);
		freopen("FILENAME.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> required[i];
	}

	cin >> a;

	for (int i = 0; i < n; i++) {
		cin >> drinks[i];
	}

	priority_queue<ll, vector<ll>, greater<ll>> available;

	ll cost = 0;
	for (int i = 0; i < n; i++) {
		//Put drink i into queue
		available.push(drinks[i]);

		while (k < required[i]) {
			if (available.size() == 0) {
				cout << -1 << endl;
				return 0;
			}
			k += a;
			cost += available.top(); available.pop();
		}
	}
	cout << cost << endl;
}