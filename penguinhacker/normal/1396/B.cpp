#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

bool calc(vector<int> v, int cant) {
	int n=v.size();
	bool win=0;
	for (int i=0; i<n; ++i) {
		if (v[i]==0||i==cant) continue;
		vector<int> nxt=v;
		--nxt[i];
		win|=!calc(nxt, i);
	}
	return win;
}

void solve() {
	int n; cin >> n;
	vector<int> v(n); for (auto &i : v) cin >> i;
	//cout << (calc(v, -1)?"T":"HL") << " ";
	/*sort(v.begin(), v.end());
	int s1=0, s2=0;
	while(v.size()) {
		int x=v.back(); v.pop_back();
		if (s1<=s2) {
			s1=x;
		}
		else {
			s2=x;
		}
		int m=min(s1, s2);
		s1-=m, s2-=m;
	}*/
	multiset<int> s(v.begin(), v.end());
	int turns=0, last=-1;
	while(s.size()>=2) {
		++turns;
		if (*s.rbegin()!=last) {
			int x=*s.rbegin();
			s.erase(prev(s.end()));
			if (x-1>0)
			s.insert(x-1);
			last=x-1;
		}
		else {
			auto it=prev(prev(s.end()));
			int x=*it;
			s.erase(it);
			if (x-1>0)
			s.insert(x-1);
			last=x-1;
		}
	}
	cout << (turns%2==0?"T":"HL") << "\n";
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