#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

void KMP(std::vector<pair<char, int> > &text, std::vector<pair<char, int> >& pattern) {
	std::vector<pair<char, int> > s; 
	s.insert(s.end(), pattern.begin() + 1, pattern.end() - 1);
	s.pb('$', 1);
	s.insert(s.end(), text.begin(), text.end());
	int l = s.size();

	int lengthofpattern = pattern.size() - 2;
	std::vector<int> lps(l);
	lps[0] = 0;
	int templps;
	int count = 0;
	for (int i = 1; i < l; ++i)
	{
		templps = lps[i-1];
		while(templps != 0 && s[i] != s[templps]) 
			templps = lps[templps-1];
		if(s[i] == s[templps]) templps++;
		lps[i] = templps;
	}
	auto fi = pattern[0];
	auto la = *(pattern.rbegin());
	for (int i = 0; i < l - 1; ++i)
		if(lps[i] == lengthofpattern) {
			if ((s[i - lengthofpattern].first == fi.first && s[i - lengthofpattern].second >= fi.second) && (s[i + 1].first == la.first && s[i + 1].second >= la.second)) 
			count++;
		}
	cout << count << "\n";
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	std::vector<pair<char, int> > te;
	std::vector<pair<char, int> > pa;
	char pr = '-';
	int si = 0;
	for (int i = 0; i < n; ++i) {
		int o; cin >> o;
		string a; cin >> a;
		if (a[1] == pr) {
			te[si - 1].second += o;
		} else {
			si++;
			pr = a[1];
			te.pb(a[1], o);
		}
	}
	pr = '-';
	si = 0;
	for (int i = 0; i < m; ++i) {
		int o; cin >> o;
		string a; cin >> a;
		if (a[1] == pr) {
			pa[si - 1].second += o;
		} else {
			si++;
			pr = a[1];
			pa.pb(a[1], o);
		}
	}
	if (pa.size() == 1) {
		int c = 0;
		for (int i = 0; i < te.size(); ++i) {
			if (te[i].first == pa[0].first && pa[0].second <= te[i].second) 
				c += (te[i].second - pa[0].second + 1ll);
		}
		cout << c << "\n";
	} else if(pa.size() == 2) {
		int c = 0;
		for (int i = 1; i < te.size(); ++i) {
			if ((te[i - 1].first == pa[0].first && te[i - 1].second >= pa[0].second) && (te[i].first == pa[1].first && te[i].second >= pa[1].second)) 
				c++;
		} 
		cout << c << "\n";
	} else {
		KMP(te, pa);
	}
}