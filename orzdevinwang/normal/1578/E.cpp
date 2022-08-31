#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e6 + 7;
int n, r[N], pos[N], tp;
char s[N];
ll sum, a[N], b[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> (s + 1), n = strlen(s + 1);
	if(n & 1) return cout << -1 << '\n', 0;
	int cnt = 0, pcnt = 0;
	L(i, 1, n) {
		if(s[i] == '(') cnt += 1, pcnt += 1;
		if(s[i] == ')') cnt -= 1, pcnt -= 1;
		if(s[i] == '?') ++tp, pcnt += 1, pos[tp] = i, r[tp] = cnt;
		if(tp) r[tp] = min(r[tp], cnt);
		if(pcnt < 0) 
			return cout << -1 << '\n', 0;
	}
	pcnt = 0;
	R(i, n, 1) {
		if(s[i] == '(') pcnt -= 1;
		else pcnt += 1;
		if(pcnt < 0) return cout << -1 << '\n', 0;
	} 
	L(i, 1, tp) r[i] = (i - r[i] + 1) / 2, r[i] = max(r[i], 0), s[pos[i]] = ')';
	r[tp] = (tp - cnt) / 2; 
	if(r[tp] < 0) return cout << -1 << '\n', 0;
	L(i, 2, tp) r[i] = max(r[i], r[i - 1]);
	R(i, tp, 2) r[i - 1] = max(r[i - 1], r[i] - 1); 
	L(i, 1, tp) cin >> a[i] >> b[i], a[i] -= b[i], sum += b[i];
	priority_queue < pair < int, int > > q; 
	L(i, 1, tp) {
		q.push({-a[i], pos[i]});
		if(r[i] - r[i - 1]) 
			sum += -q.top().first, s[q.top().second] = '(', q.pop();
	}
	cout << sum << '\n' << (s + 1) << '\n';
	return 0;
}