#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int n;
vector<int> now, lft;
vector<pair<int, int> > ans;
bool np[maxn + 10];
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i *= 2) np[i] = 1;
	for (int i = 3; i * 2 <= n; ++i)
		if (!np[i]) {
			now.clear();
			for (int j = i; j <= n; j += i)
				if (!np[j]) {
					now.push_back(j);
					np[j] = 1;
				}
			int lst = 0;
			for (auto j: now) {
				if (now.size() % 2 && j == i * 2) lft.push_back(j);
				else if (!lst) lst = j;
				else {
					ans.push_back(make_pair(lst, j));
					lst = 0;
				}
			}
		}
	for (int i = 2; i <= n; i *= 2) lft.push_back(i);
	for (int i = 0; i + 1 < (int)lft.size(); i += 2)
		ans.push_back(make_pair(lft[i], lft[i + 1]));
	printf("%d\n", (int)ans.size());
	for (auto i: ans)
		printf("%d %d\n", i.first, i.second);
}