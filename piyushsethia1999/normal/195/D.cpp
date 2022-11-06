#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
double eps = 1e-15;
bool cmp(std::pair<int, int>& p, std::pair<int, int>& q)
{
	ll k1 = p.first;
	ll k2 = q.first;
	ll b1 = -p.second;
	ll b2 = -q.second;
	ll p1 = k2*b1;
	ll p2 = k1*b2;
	return (p1 < p2);
}

bool eq(std::pair<int, int>& p, std::pair<int, int>& q)
{
	ll k1 = p.first;
	ll k2 = q.first;
	ll b1 = -p.second;
	ll b2 = -q.second;
	ll p1 = k2*b1;
	ll p2 = k1*b2;
	return (p1 == p2);
}

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);cout.precision(15);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n;
	cin >> n;
	std::vector<std::pair<int, int> > v;
	int x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		if(x != 0) {
			if(x < 0)
				v.pb(mp(-x, -y));
			else
				v.pb(mp(x, y));
		}
	}
	sort(v.begin(), v.end(), cmp);
	print(v);
	int t = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		while(i + 1 < (v.size()) && (eq(v[i], v[i+1])))
			i++;
		t++;
	}
	cout << t;
}