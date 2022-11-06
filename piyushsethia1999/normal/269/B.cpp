#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, a;
	double d;
	cin >> n >> a;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i] >> d;
	}
	std::vector<int> m;
	m.push_back(v[0]);
	int size = 1;
	for (int i = 1; i < n; ++i)
	{
		int maxpos = upper_bound(m.begin(), m.end(), v[i]) - m.begin();
		if(maxpos == size) {
			m.push_back(v[i]);
			size++;
		} else {
			m[maxpos] = v[i];
		}
	}
	cout<<n-size;
}