#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<int, int> mp;
	queue<int> q;
	q.push(0);
	q.push(0);
	q.push(0);
	int sum = 0;
	int cur = 0;
	int cnt = 0;
	while (1)
	{
		cnt++;
		int v = q.front();
		q.pop();
		cur += 2 * (sum - v);
		//cout << "iter " << cnt << " " << sum << " " << v << endl;
		mp[cur] = cnt;
		v++;
		sum++;
		q.push(v);
		//cout << "map " << cur << " " << cnt << endl;
		if (cur >= 1E9)
			break;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << (mp.lower_bound(n)->second) << "\n";
	}
	return 0;
}