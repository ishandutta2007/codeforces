#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	int n; cin >> n;
	int v[200000];
	for (int o = 0; o < n; ++o) { cin >> v[o]; }
	sort(v, v + n);
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		if(i != 0)
		{
			while(i < n && v[i] == v[i-1])
				i++;
			if(i == n)
				break;
		}
		int pos = i; 
		for (int j = 2*v[i]; j <= (v[n-1] + v[i]); j += v[i])
		{
			pos = (lower_bound(v + pos, v + n, j) - v);
			if(pos >= i) {
				m = max (m, (v[pos-1] - (j - v[i])));
			}
		}
	}
	cout<<m;
}