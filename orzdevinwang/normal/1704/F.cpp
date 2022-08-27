#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n;
char s[N];
int sg[N], cnt[N];
void init(int n) {
	L(i, 2, 1000) {
		L(j, 0, i - 2) {
			cnt[sg[j] ^ sg[i - 2 - j]] = true;
		} 
		while(cnt[sg[i]]) ++sg[i];
		L(j, 0, i - 2) {
			cnt[sg[j] ^ sg[i - 2 - j]] = false;
		} 
	}
	L(i, 1001, n) 
		sg[i] = sg[i - 34];
}
void Main() {
	cin >> n ;
	cin >> (s + 1);
	int cnt1 = 0, cnt2 = 0;
	L(i, 1, n) {
		cnt1 += s[i] == 'R';
		cnt2 += s[i] == 'B';
	} 
	if(cnt1 > cnt2) {
		cout << "Alice\n";
		return ;
	}
	if(cnt1 < cnt2) {
		cout << "Bob\n";
		return ;
	}
	int cur = 0, ns = 0;
	L(i, 1, n) {
		if(s[i] == s[i - 1]) 
			ns ^= sg[cur], cur = 0;
		cur += 1;
	}
	ns ^= sg[cur];
	if(ns) {
		cout << "Alice\n"; 
	} else {
		cout << "Bob\n";
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	const int xn = 5e5;
	init(xn);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}