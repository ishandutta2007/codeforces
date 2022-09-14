#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long ll;

int tim[100005];
vector <int> spis[100005], my;

int main()
{
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
 	ios_base::sync_with_stdio(0); cin.tie(0);
 	int n, k;
 	cin >> n >> k;
 	for (int i = 1; i <= n; i++)
 	{
 	 	int finish;
 	 	cin >> finish;
 	 	spis[finish].pb(i);	
 	}
 	for (int i = 1; i <= n; i++) cin >> tim[i];

 	for (int i = 1; i <= k; i++)
 	{
 	 	sort(spis[i].begin(), spis[i].end(), [] (int x, int y) {return tim[x] < tim[y];});
 	 	for (int j = 0; j < (int) spis[i].size() - 1; j++) my.pb(spis[i][j]);
 	}
 	sort(my.begin(), my.end(), [] (int x, int y) {return tim[x] > tim[y];});

 	ll ans = 0;
 	for (int i = 1; i <= k; i++)
 	{
 	 	if (!spis[i].empty()) continue;
 	 	ans += (ll) tim[my.back()];
 	 	my.pop_back();
 	}
 	cout << ans << '\n';
 	return 0;
}