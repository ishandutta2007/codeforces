#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define mp make_pair
#define F first
#define S second

using namespace std;

void merge(std::vector<std::pair<int, int> > &a, std::vector<int>& fill, int s1, int e1, int s2, int e2)
{
	std::vector<std::pair<int, int> > t1(e1 - s1 + 1);
	std::vector<std::pair<int, int> > t2(e2 - s2 + 1);
	int i1 = 0;
	int i2 = 0;
	int i3 = s1;
	for (int i = 0; i < e1 - s1 + 1; ++i)
		t1[i] = a[s1 + i];
	for (int i = 0; i < e2 - s2 + 1; ++i)
		t2[i] = a[s2 + i];
	while(i1 < (e1 - s1 + 1) && i2 < (e2 - s2 + 1))
	{
		if(t1[i1].F < t2[i2].F)
			a[i3++] = t1[i1++];
		else {
			a[i3++] = t2[i2++];
			fill[t2[i2 - 1].S] += (e1 - s1 + 1 - i1);
		}
	}
	while(i1 < (e1 - s1 + 1))
		a[i3++] = t1[i1++];
	while(i2 < (e2 - s2 + 1))
		a[i3++] = t2[i2++];
}

void mergesort(std::vector<std::pair<int, int> > &a, std::vector<int>& fill, int s, int e)
{
	if(s == e)
		return;
	int m = (s + e) / 2;
	mergesort(a, fill, s, m);
	mergesort(a, fill, m + 1, e);
	merge(a, fill, s, m, m + 1, e);
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
	vector<std::pair<int, int> > v(n); for (int o = 0; o < n; ++o) { cin >> v[o].F; v[o].S = o;}
	std::vector<int> fill(n, 0);
	mergesort(v, fill, 0, n-1);
	int res = 0;
	for (int i = 0; i < n; ++i)
		res += (i - v[i].S + fill[v[i].S]) * fill[v[i].S];
	cout << res;
}