#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define mp make_pair

using namespace std;
std::vector<int> cnt;
std::priority_queue< pair<int, int>, std::vector<std::pair<int, int> > , greater<std::pair<int, int> > > pq;

int getmin(int totalno, int n, int m)
{
	auto pq1 = pq;
	std::vector<int> h(m, 0);
	int rem = totalno - cnt[0];
	for (int i = 0; i < m; ++i)
		if(cnt[i] >= totalno) {
			h[i] = cnt[i] - (totalno - 1);
			rem -= h[i];
		}
	int tc = 0;
	while(!pq1.empty())
	{
		auto po = pq1.top();
		pq1.pop();
		int c = po.first; int p = po.second;
		if(h[p] > 0) {
			h[p]--;
			tc += c;
		}
		else if(rem > 0) {
			rem--;
			tc += c;
		}
	}
	return tc;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int n; cin >> n;
	int m; cin >> m;
	cnt.resize(m, 0);
	for (int i = 0; i < n; ++i)
	{
		int p, c;
		cin >> p >> c;
		p--;
		cnt[p]++;
		if(p != 0)
			pq.push({c, p});
	}
	int mi = 1000000000000000ll;
	for (int i = max(cnt[0], 1ll); i <= n; ++i)
	{
		mi = min(mi, getmin(i, n, m));
	}
	cout << mi;
}