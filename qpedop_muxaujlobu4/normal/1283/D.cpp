#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<queue>
using namespace std;

int main() {
	set<long long>VIS;
	priority_queue<pair<long long, long long>>Coord;
	const long long INF = 1000000000000000;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<long long>ViVod;
	ViVod.reserve(m);
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		VIS.insert(tmp);
		Coord.push({ INF,tmp });
	}
	while (m) {
		pair<long long, long long>tmp = Coord.top();
		long long f = INF-tmp.first, s = tmp.second;
		if (VIS.find(s + 1) == VIS.end()) {
			VIS.insert(s + 1);
			res += f + 1;
			Coord.push({ INF-f - 1,s + 1 });
			--m;
			ViVod.push_back(s + 1);
		}
		else {
			if (VIS.find(s - 1) == VIS.end()) {
				VIS.insert(s - 1);
				res += f + 1;
				Coord.push({ INF-f - 1,s - 1 });
				--m;
				ViVod.push_back(s - 1);
			}
			else Coord.pop();
		}
	}
	cout << res << endl;
	for (auto x : ViVod)cout << x << " ";
	return 0;
}