#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

std::vector<ll> res;

void KMP(string text, string pattern) {
	string s = pattern + "$" + text;
	int l = s.size();
	res.resize(l + 1, 0);
	int lengthofpattern = pattern.size();
	std::vector<int> lps(l);
	
	lps[0] = 0;
	int templps;	

	for (int i = 1; i < l; ++i)
	{
		templps = lps[i-1];
		while(templps != 0 && s[i] != s[templps]) 
			templps = lps[templps-1];
		if(s[i] == s[templps]) templps++;
		lps[i] = templps;
	}


	for (int i = 1; i < l; ++i) {
		res[i] = res[i-1];
		if(lps[i] == lengthofpattern)
			res[i]++;
	}
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	ll n; cin >> n;
	ll m; cin >> m;
	ll q; cin >> q;
	string s; cin >> s;
	string t; cin >> t;
	KMP(s, t);
	while(q--)
	{
		int l; cin >> l;
		int r; cin >> r;
		if(m + l - 2 - r < 0)
			cout << max(res[m + r] - res[2 * m + l - 2], 0ll) << "\n";
		else
			cout << 0 << "\n";
	}
}