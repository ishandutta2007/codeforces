#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e18 + 7;

string prev1(string a) {
	for(int i = a.size() - 1;i >= 0;i--) {
		if (a[i] == '0') continue;
		for(int j = i + 1;j < a.size();j++) a[j] = '1';
		a[i] = '0';
		break;
	}
	return a;
}

string next1(string a) {
	for(int i = a.size() - 1;i >= 0;i--) {
		if (a[i] == '1') continue;
		for(int j = i + 1;j < a.size();j++) a[j] = '0';
		a[i] = '1';
		break;
	}
	return a;
}

vector<string> s;
string res;

bool have() {
	for(string i : s) if (i.compare(res) == 0) return true;
	return false;
}


signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
    	s.clear();
    	res.clear();

    	int n, m;
    	cin >> n >> m;
    	s.resize(n);
    	for(int i = 0;i < n;i++) cin >> s[i];


    	if (m <= 9) {
    		for(int i = 0;i < m;i++) res += '0';
    		int cnt = 0;
    		while(true) {
    			while(have()) res = next1(res);
    			cnt++;
    			if (cnt == ((1 << m) - n + 1) / 2) break;
    			res = next1(res);
    		}
    		cout << res << endl;
    		continue;
    	}


    	res = "1";
    	for(int i = 0;i < m - 1;i++) res += '0';

    	int cnt1 = (1 << (m - 1));
    	int cnt2 = (1 << (m - 1)) - 1;

    	while(have()) {
    		res = next1(res);
    		cnt1++;
    		cnt2--;
    	}

    	for(int i = 0;i < n;i++) {
    		if (res.compare(s[i]) < 0) cnt2--;
    		if (res.compare(s[i]) > 0) cnt1--;
    	}

    	while(cnt1 < cnt2) {
    		res = next1(res);
    		while(have()) res = next1(res);
    		cnt2--;
    		cnt1++;
    	}

    	while(cnt2 < cnt1) {
    		res = prev1(res);
    		while(have()) res = prev1(res);
    		cnt1--;
    		cnt2++;
    	}

    	cout << res << endl;
    }
}