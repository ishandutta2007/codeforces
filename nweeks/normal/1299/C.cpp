#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 1e6;

ll cap[MAXN];
double capp[MAXN];
int n;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i(0); i < n; ++i)
		cin >> cap[i];
	
	stack<pair<int, ll> > s;

	for (int i(n-1); i >= 0; --i)
	{
		pair<int, ll> p = {1, cap[i]};
		while (s.size() > 0 and (s.top().second * p.first < p.second * s.top().first))
		{
			p.first += s.top().first;
			p.second += s.top().second;
			s.pop();
		}
		s.push(p);
	}

	while (!s.empty())
	{
		auto cur = s.top(); s.pop();
		double c = cur.second/ (double)cur.first;
		while (cur.first--)
			cout << setprecision(12) << fixed << c << ' ';
	}
	cout << endl;
}