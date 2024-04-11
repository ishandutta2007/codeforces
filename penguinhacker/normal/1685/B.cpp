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
		int a, b, c, d;
		string s;
		cin >> a >> b >> c >> d >> s;
		int ca=0, cb=0;
		int n=s.size();
		for (int i=0; i<n; ++i) {
			ca+=s[i]=='A';
			cb+=s[i]=='B';
		}
		if (ca-c-d!=a||cb-c-d!=b) {
			cout << "NO\n";
			continue;
		}
		multiset<int> oc[2];
		int free=0;
		for (int i=0; i+1<n;) {
			if (s[i]==s[i+1]) {
				++i;
				continue;
			}
			int j=i+1;
			while(j+1<n&&s[j]!=s[j+1])
				++j;
			if ((j-i)%2)
				oc[s[i]-'A'].insert((j-i+1)/2);
			else
				free+=(j-i)/2;
			i=j+1;
		}
		while(c&&oc[0].size()) {
			int x=*oc[0].begin();
			oc[0].erase(oc[0].begin());
			--c;
			if (x>1)
				oc[0].insert(x-1);
		}
		while(d&&oc[1].size()) {
			int x=*oc[1].begin();
			oc[1].erase(oc[1].begin());
			--d;
			if (x>1)
				oc[1].insert(x-1);
		}
		for (int i : {0, 1})
			for (int j : oc[i])
				free+=j-1;
		cout << (free>=c+d?"YES":"NO") << "\n";
	}
	return 0;
}