#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair
#define pii std::pair<int, int>
#define F first
#define S second

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m;
	cin >> m >> n;
	std::vector<pii> v(n);
	std::vector<int> t(n, 0);
	std::map<ll, int> mk;
	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		int b; cin >> b;
		mk[(ll)a*(ll)100001 + (ll)b] = i;
		v[i] = {a, b};		
	}
	sort(v.begin(), v.end(), [](pii p1, pii p2){return (p1.F < p2.F || (p1.F == p2.F && p1.S < p2.S));});
	for (int i = 0; i < n-1; ++i)
		if(v[i+1].F == v[i].F) {
			t[mk[((ll)v[i].F)*100001l + (ll)v[i].S]]++;
			t[mk[((ll)v[i+1].F)*100001l + (ll)v[i+1].S]]++;
		}
	print(t, v);
	sort(v.begin(), v.end(), [](pii p1, pii p2){return (p1.S < p2.S || (p1.S == p2.S && p1.F < p2.F));});
	for (int i = 0; i < n-1; ++i)
		if(v[i+1].S == v[i].S) {
			t[mk[((ll)v[i].F)*100001l + (ll)v[i].S]]++;
			t[mk[((ll)v[i+1].F)*100001l + (ll)v[i+1].S]]++;
		}
	print(t, v);
	sort(v.begin(), v.end(), [](pii p1, pii p2){return ((p1.F + p1.S) < (p2.S + p2.F) || ((p1.F + p1.S) == (p2.S + p2.F) && p1.F < p2.F));});
	for (int i = 0; i < n-1; ++i)
		if((v[i+1].F + v[i+1].S) == (v[i].F + v[i].S)) {
			t[mk[((ll)v[i].F)*100001l + (ll)v[i].S]]++;
			t[mk[((ll)v[i+1].F)*100001l + (ll)v[i+1].S]]++;
		}
	print(t, v);
	sort(v.begin(), v.end(), [](pii p1, pii p2){return ((p1.F - p1.S) < (p2.F - p2.S) || ((p1.F - p1.S) == (p2.F - p2.S) && p1.F < p2.F));});
	for (int i = 0; i < n-1; ++i)
		if((v[i+1].F - v[i+1].S) == (v[i].F - v[i].S)) {
			t[mk[((ll)v[i].F)*100001l + (ll)v[i].S]]++;
			t[mk[((ll)v[i+1].F)*100001l + (ll)v[i+1].S]]++;
		}
	print(t, v);
	sort(t.begin(), t.end());
	std::vector<int> inn(9, 0);
	for (int i = 0; i < n; ++i)
		inn[t[i]]++;
	for (int i = 0; i < 9; ++i)
		cout << inn[i] << " ";
}