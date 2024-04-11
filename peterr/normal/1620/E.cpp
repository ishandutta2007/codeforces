#include <bits/stdc++.h>
 
using namespace std;

const int MAXQ = 5E5;
tuple<int, int, int> queries[MAXQ];
int who[MAXQ + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= MAXQ; i++)
	{
		who[i] = i;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int type, x;
		cin >> type >> x;
		if (type == 1)
			queries[i] = {type, x, 0};
		else
		{
			int y;
			cin >> y;
			queries[i] =  {type, x, y};
		}
	}
	reverse(queries, queries + q);
	vector<int> ans;
	for (int i = 0; i < q; i++)
	{
		tuple<int, int, int> tup = queries[i];
		if (get<0>(tup) == 1)
		{
			ans.push_back(who[get<1>(tup)]);
		}
		else
		{
			who[get<1>(tup)] = who[get<2>(tup)];
		}
	}
	reverse(ans.begin(), ans.end());
	for (int x : ans)
		cout << x << " ";
	cout << "\n";
	return 0;
}