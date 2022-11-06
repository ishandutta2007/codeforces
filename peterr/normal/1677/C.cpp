#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E5;
int a[MAXN + 1];
int b[MAXN + 1];
bool visited[MAXN + 1];
vector<int> cycles;
int where_[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		fill(visited + 1, visited + n + 1, false);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			where_[a[i]] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
		}
		cycles.clear();
		for (int i = 1; i <= n; i++)
		{
			if (visited[i])
				continue;
			visited[i] = true;
			int j = where_[b[i]];
			int cnt = 1;
			while (j != i)
			{
				visited[j] = true;
				cnt++;
				j = where_[b[j]];
			}
			cycles.push_back(cnt);
			//cout << "pushing " << i << " "<< cnt << endl;
		}
		sort(cycles.rbegin(), cycles.rend());
		vector<int> vec;
		int lo = 1;
		int hi = n;
		while (lo <= hi)
		{
			vec.push_back(lo);
			lo++;
			if (lo <= hi)
			{
				vec.push_back(hi);
				hi--;
			}
		}
		long long ans = 0;
		reverse(vec.begin(), vec.end());
		//cout << "VEC " << endl;
		//for (int x : vec)
			//cout << "\t" << x << endl;
		int ptr = 0;
		for (int x : cycles)
		{
			bool odd = x % 2;
			//cout << "CYCLES " << x << endl;
			int first = vec.back();
			int prev = first;
			vec.pop_back();
			//cout << "cur " << first	 << endl;
			for (int i = 0; i < x - 1; i++)
			{
				int cur = vec.back();
				if (odd && i == x - 2)
				{
					cur = vec[ptr];
					ptr++;
				}
				else
					vec.pop_back();
				//cout << "cur " << cur << endl;
				ans += abs(cur - prev);
				prev = cur;
			}
			ans += abs(first - prev);
		}
		cout << ans << "\n";
	}
	return 0;
}