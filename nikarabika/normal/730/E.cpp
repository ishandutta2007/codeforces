#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 7;

#define F first
#define S second

pair<int, int> a[N];
int ind[N], cur[N];
int pos[N], sop[N];

bool dir(pair<int, int> p)
{
	return p.first < p.second;
}

bool cmp(int x, int y)
{
	if (dir(a[x]) == dir(a[y]))
	{	
		if (dir(a[x]) == 0)
			return a[x].first > a[y].first;
		return a[x].first < a[y].first;
	}
	return dir(a[x]) > dir(a[y]);
}

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> a[i].first >> a[i].second;
		a[i].second = a[i].first + a[i].second;
		a[i].first = a[i].first * N - i;
		a[i].second = a[i].second * N - i;
	}
	sort(a, a+n);
	/*for (int i=0; i<n; i++)
		cout << a[i].F << " " << a[i].S << "\n";*/
	for (int i=0; i<n; i++)
		pos[i] = i, sop[i] = i, cur[i] = a[i].F;
	for (int i=0; i<n; i++)
		ind[i] = i;
	sort(ind, ind+n, cmp);
	/*for (int i=0; i<n; i++)
		cout << ind[i] << " ";
	cout << "\n";*/
	int ans = 0;
	for (int i=0; i<n; i++)
	{
		int p = sop[ind[i]];
		cur[p] = a[ind[i]].S;
		while (p+1 < n && cur[p] > cur[p+1])
		{
			swap(cur[p], cur[p+1]);
			swap(pos[p], pos[p+1]);
			sop[pos[p]] = p;
			sop[pos[p+1]] = p+1;
			p++;
			ans++;
		}
		while (p-1 >= 0 && cur[p] < cur[p-1])
		{
			swap(cur[p], cur[p-1]);
			swap(pos[p], pos[p-1]);
			sop[pos[p]] = p;
			sop[pos[p-1]] = p-1;
			p--;
			ans++;
		}
		/*cout << ind[i] << " : \n";
		for (int i=0; i<n; i++)
			cout << cur[i] << " ";
		cout << "\n";
		cout << ans << "\n";*/
	}
	cout << ans << "\n";
	return 0;
}