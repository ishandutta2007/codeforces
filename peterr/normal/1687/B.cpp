#include <bits/stdc++.h>

using namespace std;

const int MAXM = 500;
pair<int, int> a[MAXM];
bool active[MAXM];
int n;
int m;

long long query()
{
	cout << "? ";
	for (int i = 0; i < m; i++)
	{
		cout << active[i];
	}
	cout << endl;
	long long q;
	cin >> q;
	return q;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		active[i] = true;
		a[i] = {query(), i};
		active[i] = false;
	}
	sort(a, a + m);
	long long cur = 0;
	for (int i = 0; i < m; i++)
	{
		int ind = a[i].second;
		active[ind] = true;
		long long q = query();
		if (q == cur + a[i].first)
			cur = q;
		else
			active[ind] = false;
	}
	cout << "! " << cur << endl;
	return 0;
}