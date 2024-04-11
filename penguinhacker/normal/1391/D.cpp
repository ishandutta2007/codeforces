#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
vector<string> g;

inline int get(string s) {
	int res=0;
	for (char c: s)
		if (c=='1')
			res^=1;
	return res;
}

int solve(string par) {
	string op=par;
	for (char &c: op) c=(c=='1'?'0':'1');
	int res=0;
	for (int i=0; i<m; ++i) {
		const string &comp=(i%2)?op:par;
		int minAdd=1e9;
		for (int j=0; j<(1<<n); ++j) {
			int cur=0;
			string nxt(n, '0');
			for (int k=0; k<n; ++k)
				if (j&(1<<k))
					nxt[k]='1';
			string real(n-1, '0');
			for (int k=0; k<n-1; ++k)
				if ((nxt[k]=='1')^(nxt[k+1]=='1'))
					real[k]='1';
			if (real!=comp) continue;
			for (int k=0; k<n; ++k)
				if (g[k][i]!=nxt[k])
					++cur;
			//cout << nxt << ' ' << real << ' ' << comp << '\n';
			minAdd=min(minAdd, cur);
		}
		res+=minAdd;
		//cout << minAdd << '\n';
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	g.resize(n);
	for (int i=0; i<n; ++i)
		cin >> g[i];
	if (min(n, m)>=4) {
		cout << -1;
		return 0;
	}
	if (min(n, m)<2) {
		cout << 0;
		return 0;
	}
	//make n<m
	if (n>m) {
		vector<string> temp;
		for (int i=0; i<m; ++i) {
			string cur="";
			for (int j=0; j<n; ++j)
				cur+=g[j][i];
			temp.push_back(cur);
		}
		g=temp;
		swap(m, n);
	}
	int ans=1e9;
	string st="";
	for (int i=0; i<n; ++i) st.push_back(g[i][0]);
	if (n==2) {
		ans=min(ans, solve("0"));
		ans=min(ans, solve("1"));
	}
	else {
		ans=min(ans, solve("01"));
		ans=min(ans, solve("11"));
		ans=min(ans, solve("00"));
		ans=min(ans, solve("10"));
	}
	cout << ans << '\n';
	return 0;
}


/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/