#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
vector<string> p;

bool isLess(string s1, string s2) { //s1<s2
	if (s1.size()!=s2.size()) return s1.size()<s2.size();
	return s1<s2;
}

void solve() {
	cin >> n >> k;
	n-=k*(k+1)/2;
	p.clear();
	for (int i=0; i<10; ++i) {
		if (i+k<10) {
			if (n<0||n%(k+1)!=0) continue;
			int x=n/(k+1);
			x-=i;
			string s="";
			s.push_back((char)i+'0');
			while(x>=9) {
				x-=9;
				s.push_back('9');
			}
			if (x>0) s.push_back((char)x+'0');
			reverse(s.begin(), s.end());
			p.push_back(s);
			continue;
		}
		for (int j=0; j<1000; ++j) {
			if (i+9*j>n)
				break;
			if ((n+9*(i+k-9)*(j+1))%(k+1)!=0)
				continue;
			int x=(n+9*(i+k-9)*(j+1))/(k+1);
			if (x-9*j-i<0)
				continue;
			string s="";
			s.push_back((char)i+'0');
			for (int lol=0; lol<j; ++lol)
				s.push_back('9');
			x-=9*j+i;
			if (x<=8) {
				if (x>0)
					s.push_back((char)x+'0');
			}
			else {
				s.push_back('8');
				x-=8;
				while(x>=9) {
					x-=9;
					s.push_back('9');
				}
				if (x>0)
					s.push_back((char)x+'0');
			}
			reverse(s.begin(), s.end());
			p.push_back(s);
		}
	}
	if (p.empty()) {
		cout << "-1\n";
		return;
	}
	string ans=p[0];
	for (string s : p)
		if (isLess(s, ans))
			ans=s;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/