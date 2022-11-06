#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int n, a, b;

int floord(int x, int y)
{
	if(x < 0)
		return 0;
	return (x / y + (x % y ? 1 : 0));
}

bool cmpless(std::pair<int, int> p1, std::pair<int, int> p2)
{
	return (p1.first < p2.first || (p1.first == p2.first && (p1.second > p2.second)));
}

std::vector<int> oo(std::vector<int>& h)
{
	std::vector<std::vector<std::pair<int, int> > > v(n);
	std::vector<std::vector<std::vector<int> > > P(n);
	for (int i = 0; i < n; ++i)
	{
		v[i].resize(h[i]+1, mp(1000000, 1000000));
		P[i].resize(h[i]+1);
	}
	v[0][h[0]] = mp(0, 0);
	P[0][h[0]].pb(0);
	for (int i = 1; i < n-2; ++i)
	{
		for (int j = 0; j <= h[i]; ++j)
		{
			for (int k = 0; k <= h[i-1]; ++k)
			{
				int t = v[i-1][k].first;
				int at = v[i-1][k].second;
				int a1 = max(floord(k, b), floord(h[i] - at*b - j, a));
				if(cmpless(mp(t+a1, a1), v[i][j])) {
					v[i][j] = mp(t + a1, a1);
					P[i][j] = P[i-1][k];
					P[i][j].pb(a1);
				}
			}
		}
	}
	int prin;
	for (int i = 0; i <= h[n-3]; ++i)
	{
		int t = v[n-3][i].first;
		int at = v[n-3][i].second;
		int prev = i;
		int curr = h[n-2] - b*at;
		int ahea = h[n-1];
		int a1 = max(max(floord(prev, b), floord(curr, a)), floord(ahea, b));
		t += a1;
		if(cmpless(mp(t,a1), v[n-2][0])) {
			v[n-2][0] = mp(t, a1);
			prin = i;
			P[n-2][0] = P[n-3][i];
			P[n-2][0].pb(a1);
		}
	}
	// print(P);
	// cout << v[n-2][0].first << '\n';
	// for (int i = 0; i < n - 1; ++i)
	// 	for (int j = 0; j < P[n-2][0][i]; ++j)
	// 		cout << i+1 << " ";
	// cout << "\n" << P[n-2][0][0]*a + P[n-2][0][1]*b;
	// for (int i = 1; i < n-2; ++i)
	// 	cout << " " << P[n-2][0][i]*a + P[n-2][0][i-1]*b + P[n-2][0][i+1]*b;
	// cout << " " << P[n-2][0][n-2]*a + P[n-2][0][n-3]*b << " " << P[n-2][0][n-2]*b << "\n";
	// int m = v[n-2][0].first - v[n-2][0].second;
	// int in = prin;
	// cout << v[n-2][0].first << "\n";
	// for (int i = 0; i < v[n-2][0].second; ++i)
	// 	cout << n-1 << " ";
	// for (int i = n-3; i >= 1 ; --i)
	// {
	// 	print(i, in, m);
	// 	int th = in;
	// 	int att = v[i][in].second;
	// 	for (int j = 0; j < att; ++j)
	// 		cout << i+1 << " ";
	// 	int nb = floord(h[i] - th - att*a, b);
	// 	m -= att;
	// 	// print(m, nb, v[i-1]);
	// 	for (int j = 0; j <= h[i-1]; ++j)
	// 		if(v[i-1][j].first == m && v[i-1][j].second == nb) {
	// 			in = j;
	// 			print(in, m, nb);
	// 			break;
	// 		}
	// }
	// for (int i = 0; i < n; ++i)
	// 	print(i, h[i], v[i]);
	// print(m);
	return P[n-2][0];
}

std::vector<int> oo1(std::vector<int>& h)
{
	std::vector<std::vector<std::pair<int, int> > > v(n);
	std::vector<std::vector<std::vector<int> > > P(n);
	for (int i = 0; i < n; ++i)
	{
		v[i].resize(h[i]+1, mp(1000000, 1000000));
		P[i].resize(h[i]+1);
	}
	v[0][h[0]] = mp(0, 0);
	P[0][h[0]].pb(0);
	for (int i = 1; i < n-2; ++i)
	{
		for (int j = 0; j <= h[i]; ++j)
		{
			for (int k = 0; k <= h[i-1]; ++k)
			{
				int t = v[i-1][k].first;
				int at = v[i-1][k].second;
				int a1 = max(floord(k, b), floord(h[i] - at*b - j, a));
				if(mp(t+a1, a1) < v[i][j]) {
					v[i][j] = mp(t + a1, a1);
					P[i][j] = P[i-1][k];
					P[i][j].pb(a1);
				}
			}
		}
	}
	int prin;
	for (int i = 0; i <= h[n-3]; ++i)
	{
		int t = v[n-3][i].first;
		int at = v[n-3][i].second;
		int prev = i;
		int curr = h[n-2] - b*at;
		int ahea = h[n-1];
		int a1 = max(max(floord(prev, b), floord(curr, a)), floord(ahea, b));
		t += a1;
		if(mp(t,a1) < v[n-2][0]) {
			v[n-2][0] = mp(t, a1);
			prin = i;
			P[n-2][0] = P[n-3][i];
			P[n-2][0].pb(a1);
		}
	}
	return P[n-2][0];
	// print(P);
	// cout << v[n-2][0].first << '\n';
	// for (int i = 0; i < n - 1; ++i)
	// 	for (int j = 0; j < P[n-2][0][i]; ++j)
	// 		cout << i+1 << " ";
	// cout << "\n" << P[n-2][0][0]*a + P[n-2][0][1]*b;
	// for (int i = 1; i < n-2; ++i)
	// 	cout << " " << P[n-2][0][i]*a + P[n-2][0][i-1]*b + P[n-2][0][i+1]*b;
	// cout << " " << P[n-2][0][n-2]*a + P[n-2][0][n-3]*b << " " << P[n-2][0][n-2]*b << "\n";
	// int m = v[n-2][0].first - v[n-2][0].second;
	// int in = prin;
	// cout << v[n-2][0].first << "\n";
	// for (int i = 0; i < v[n-2][0].second; ++i)
	// 	cout << n-1 << " ";
	// for (int i = n-3; i >= 1 ; --i)
	// {
	// 	print(i, in, m);
	// 	int th = in;
	// 	int att = v[i][in].second;
	// 	for (int j = 0; j < att; ++j)
	// 		cout << i+1 << " ";
	// 	int nb = floord(h[i] - th - att*a, b);
	// 	m -= att;
	// 	// print(m, nb, v[i-1]);
	// 	for (int j = 0; j <= h[i-1]; ++j)
	// 		if(v[i-1][j].first == m && v[i-1][j].second == nb) {
	// 			in = j;
	// 			print(in, m, nb);
	// 			break;
	// 		}
	// }
	// for (int i = 0; i < n; ++i)
	// 	print(i, h[i], v[i]);
	// print(m);
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	cin >> n >> a >> b;
	std::vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		h[i]++;
	}
	std::vector<int> v1 = oo(h);
	std::vector<int> v2 = oo1(h);
	int t1 = 0;
	for (int i = 0; i < n-1; ++i)
		t1 += v1[i];
	int t2 = 0;
	for (int i = 0; i < n-1; ++i)
		t2 += v2[i];
	if(t2 < t1) {
		v1 = v2;
		t1 = t2;
	}
	cout << t1 << "\n";
	for (int i = 0; i < n-1; ++i)
		for (int j = 0; j < v1[i]; ++j)
			cout << i+1<< " ";
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << h[i] << " ";
//	}
	// cin >> n;
	// cout << "\n" << n << "\n";
	// cin >> n;
	// cout << n << "\n";
	// for (int i = 0; i < n; ++i)
	// {
	// 	cin >> h[0] ;
	// 	cout << h[0] << " ";
	// }
}