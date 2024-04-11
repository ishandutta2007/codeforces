#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
const int N = 2e6;
int n, m, cnt[N], cs[N], ct[N], wh;
char s[N], t[N];
bool check(int x) {
	int all = wh;
	L(i, 0, 25) cnt[i]  = 0;
	L(i, 0, 25) if(cs[i] < ct[i] * x) cnt[i] = ct[i] * x - cs[i], all -= cnt[i];
	cnt[0] += all;
	if(all < 0) return 0;
	else return 1;
}
int mp[N], tot;
int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s +1);
	m = strlen(t + 1);
	int l = 1, r = n / m, ans = 0;
	L(i, 1, m) ct[t[i] - 'a'] ++;
	L(i, 1, n) 
	if(s[i] != '?') cs[s[i] - 'a'] ++;
	else wh ++;
	
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	check(ans);
	L(i, 0, 25) while(cnt[i]) cnt[i] --, mp[wh--] = i;
	L(i, 1, n) {
		if(s[i] == '?') putchar(mp[++wh] + 'a');
		else putchar(s[i]);
	}
	puts("");
	return 0;
}