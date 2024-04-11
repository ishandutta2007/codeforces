#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <map>
#define ll long long
#define cs(x) (int)x.size()
#define mp make_pair
using namespace std;

const ll mod = 1000000000;


int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("kthpath.in", "r", stdin);
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> friendship(n);
	vector<bool> inlist(n);
	for (int i = 0; i < n; i++)
		cin >> friendship[i];
	set<pair<int, int> > friends;
	for (int qq = 0; qq < q; qq++) {
		int t, id;
		cin >> t >> id;
		id--;
		if (t == 2) {
			if (inlist[id])
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
		else {
			if (cs(friends) < k) {
				inlist[id] = 1;
				friends.insert(mp(friendship[id], id));
			}
			else {
				if (friends.begin()->first > friendship[id])
					continue;
				inlist[friends.begin()->second] = 0;
				friends.erase(friends.begin());
				inlist[id] = 1;
				friends.insert(mp(friendship[id], id));
			}
		}
	}
	return 0;
}