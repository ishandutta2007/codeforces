#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, O = 5e5;
int n, o[N], pre[N], lst[N], mp[N];
char s[N];
void Main() {
	int cnt0 = 0, cnt1 = 0, ns = 0;
	cin >> n >> (s + 1);
	L(i, 1, n) o[i] = s[i] - '0', cnt0 += !o[i], cnt1 += o[i];
	if(cnt0 > cnt1) {
		L(i, 1, n) o[i] ^= 1;
		reverse(o + 1, o + n + 1), swap(cnt0, cnt1);
	}
	L(i, O - n - 1, O + n + 1) mp[i] = -1;
	pre[0] = O;
	L(i, 1, n) pre[i] = pre[i - 1] + (o[i] ? 1 : -1);
	L(i, 0, n) {
		if(mp[pre[i]] == -1) mp[pre[i]] = i;
		lst[i] = mp[pre[i]];
	}
	R(t, n, 1) if(!o[t]) {
		int i = t, len = 1;
		while(i > 1 && !o[i - 1]) --i, ++len;
		if(i == 1) break ;
		int xp = i - 1, cur = len;
		if(pre[i - 1] - O <= len) {
			ns += 1;
			break;
		}
		for(; xp; --xp) {
			cur += o[xp] ? -1 : 1;
			if(!cur) {
				xp = lst[xp - 1];
				break ;
			}
		} 
		sort(o + xp + 1, o + t + 1), ns += 1;
		if(!xp) break ;
	}
	cout << ns << '\n';
}
int main () {
//	return system("fc xtq.out xtq.ans"), 0;
//	freopen("xtq.in", "r", stdin);
//	freopen("xtq.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}

/*
1
7 
0010110
*/