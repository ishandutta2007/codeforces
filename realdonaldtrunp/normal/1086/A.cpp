#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<random>
#include<unordered_set>
#include<unordered_map>

using namespace std;

vector<pair<int, int> > v;
bool r[1002][1002];
void col(int x1, int y1, int x2, int y2) {
	if (x1 > x2)swap(x1, x2);
	if (y1 > y2)swap(y1, y2);
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			r[i][j] = true;
		}
	}
}
vector<pair<int, int> > ans;
int main() {
	for (int i = 0; i < 3; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	col(v[0].first, v[0].second, v[1].first, v[0].second);
	int mint = min(v[0].second, min(v[1].second, v[2].second));
	int maxt = max(v[0].second, max(v[1].second, v[2].second));
	col(v[1].first, mint, v[1].first, maxt);
	col(v[1].first, v[2].second, v[2].first, v[2].second);
	for (int i = 0; i < 1002; i++) {
		for (int j = 0; j < 1002; j++) {
			if (r[i][j]) {
				ans.push_back(make_pair(i, j));
			}
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}