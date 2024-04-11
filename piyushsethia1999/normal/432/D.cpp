#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
void KMP(string s) {
	int l = s.size();
	std::vector<int> lps(l);
	
	lps[0] = 0;
	int templps;
	std::vector<int> m(l+1);
	for (int i = 1; i < l; ++i)
	{
		templps = lps[i-1];
		while(templps != 0 && s[i] != s[templps]) 
			templps = lps[templps-1];
		if(s[i] == s[templps]) templps++;
		lps[i] = templps;
		m[templps]++;
	}
	std::vector<int> v;
	m[l] = 1;
	for (int i = l; i >= 1 ; --i)
	{
		if(m[i] != 0)
		{
			m[lps[i-1]] += m[i];
		}
	}
	templps = l;
	while(templps != 0)
	{
		v.pb(templps);
		templps = lps[templps-1];
	}
	reverse(v.begin(), v.end());
	cout<<v.size()<<"\n";
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" "<<m[v[i]]<<"\n";
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); 
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	string s;
	cin>>s;
	KMP(s);
}