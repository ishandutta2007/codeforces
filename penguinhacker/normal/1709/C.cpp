#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int up=0;
		int down=0;
		vector<int> pos;
		for (int i=0; i<s.size(); ++i) {
			if (s[i]=='?')
				pos.push_back(i);
			else if (s[i]=='(')
				++up;
			else
				++down;
		}
		if (up==s.size()/2||down==s.size()/2) {
			cout << "YES\n";
			continue;
		}
		int x=s.size()/2-up-1;
		for (int i=0; i<x; ++i)
			s[pos[i]]='(';
		s[pos[x]]=')';
		s[pos[x+1]]='(';
		for (int i=x+2; i<pos.size(); ++i)
			s[pos[i]]=')';
		//cout << s << endl;
		int bal=0;
		bool ok=1;
		for (char c : s) {
			assert(c=='('||c==')');
			bal+=c=='('?1:-1;
			ok&=bal>=0;
		}
		cout << (ok?"NO":"YES") << "\n";
	}
	return 0;
}