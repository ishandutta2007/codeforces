#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5010;

int n;
int x[N] , y[N];
int f[N];

int sq(int x1 , int y1) {
	return x1 * x1 + y1 * y1;
}

int p[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	int l = 1; f[1] = true;
	p[1] = 1;
	for(int j = 2; j <= n; j++) {
		int Max = 0 , s = 0;
		for(int i = 1; i <= n; i++)
			if(!f[i] && sq(x[i] - x[l] , y[i] - y[l]) > Max)
				Max = sq(x[i] - x[l] , y[i] - y[l]) , s = i;
		p[j] = l = s; f[l] = 1;
	}
	for(int i = 1; i <= n; i++)
		cout << p[i] << " ";
	cout << endl;
	return 0;
}