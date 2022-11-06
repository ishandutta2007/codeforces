#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int p[MAXN + 1];
int b[MAXN + 1];
int w[MAXN + 1];
int dist[MAXN + 1];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		fill(w + 1, w + n + 1, -1);
		int root = -1;
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
			if (b[i] == i)
				root = i;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
		}
		if (p[0] != root)
		{
			cout << "-1\n";
			goto exit;
		}
		w[root] = 0;
		dist[root] = 0;
		for (int i = 1; i < n; i++)
		{
			int v = p[i];
			if (w[b[v]] == -1)
			{
				cout << "-1\n";
				goto exit;
			}
			w[v] = i - dist[b[v]];
			dist[v] = i;
		}
		for (int i = 1; i <= n; i++)
			cout << w[i] << " \n"[i == n];
		exit:;
	}
	return 0;
}