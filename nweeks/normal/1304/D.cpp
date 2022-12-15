#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

void solve(void)
{
	int n; cin >> n;
	string s;
	cin >> s;
	assert(s.size()==n-1);

	int lst(0);
	vector<int> best(n);
	vector<int> worst(n);
	for (int i(0); i < n; ++i)
		best[i]=i+1;
	for (int i(0); i < n; ++i)
		worst[i] = n-i;

	for (int i(0); i < -1+n; ++i)
	{
		if (s[i] == '<')
		{
			reverse(best.begin()+lst, best.begin() + i+1);
			lst = i+1;
		}
	}
	reverse(best.begin()+lst, best.end());

	lst=0;
	for (int i(0); i < n-1; ++i)
	{
		if (s[i]=='>')
		{
			reverse(worst.begin()+lst, worst.begin()+i+1);
			lst =i+1;
		}
	}
	reverse(worst.begin()+lst,worst.end());
	for (auto e : worst)
		cout << e<<' ';
	cout<<'\n';
	for (auto e : best)
		cout << e << ' ';
	cout << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}