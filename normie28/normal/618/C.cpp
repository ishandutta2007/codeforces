#include<bits/stdc++.h>
using namespace std; 
vector<pair<pair<long long, long long>,long long>>p;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		p.push_back({{ x,y },i+1});
	}
	sort(p.begin(), p.end());
	for (int i = 2; i < n; i++)
	{
		long long x = p[i].first.first;
		long long y = p[i].first.second;
		if ((x - p[0].first.first) * (y - p[1].first.second) != (x - p[1].first.first) * (y - p[0].first.second))
		{
			cout << p[0].second << " " << p[1].second << " " << p[i].second;
			return 0;
		}
	}
	return 0;
}