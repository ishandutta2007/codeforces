#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define sz(x) ((int) x.size())
#define be(x) x.begin()
#define en(x) x.end()
using namespace std;
const int N = 1e6 + 7;
const int mS = sqrt(N), S = mS + 5, cS = N / mS + 5;
int n, m, B, now, ml, mr, tb[N], a[N], cnt[N], mx, de, ans[N], f[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void mdf(int l, int r, int x) {
	if(r < ml || l > mr) return;
	if(tb[l] == now && tb[r] == now) {
		L(i, l, r) if((a[i] = find(a[i])) - de > x) cnt[a[i]] --, a[i] -= x, cnt[a[i]] ++;
		return;
	}
	if(tb[l] == now) L(i, l, mr) if((a[i] = find(a[i])) - de > x) cnt[a[i]] --, a[i] -= x, cnt[a[i]] ++;
	if(tb[r] == now) L(i, ml, r) if((a[i] = find(a[i])) - de > x) cnt[a[i]] --, a[i] -= x, cnt[a[i]] ++;
	if(tb[l] + 1 <= now && now <= tb[r] - 1 && x < mx) 
		if(x <= mx / 2) { 
			L(j, de + 1, de + x) cnt[j + x] += cnt[j], f[j] = j + x, cnt[j] = 0;
			de += x, mx -= x;
		}
		else { 
			L(j, de + x + 1, de + mx) cnt[j - x] += cnt[j], f[j] = j - x, cnt[j] = 0;
			mx = x;
		}
}
int qry(int l, int r, int x) {
	if(r < ml || l > mr) return 0;
	if(tb[l] + 1 <= now && now <= tb[r] - 1) return x <= mx ? cnt[x + de] : 0;
	int res = 0;
	L(i, tb[l] == now ? l : ml, tb[r] == now ? r : mr) a[i] = find(a[i]), res += (a[i] == x + de);
	return res;
}
int opt[N], l[N], r[N], x[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m, B = sqrt(n);
	L(i, 1, n) cin >> a[i], tb[i] = (i - 1) / B + 1;
	L(i, 1, m) cin >> opt[i] >> l[i] >> r[i] >> x[i];
	for(now = 1; now <= tb[n]; now++) {
		de = 0, ml = (now - 1) * B + 1, mr = min(now * B, n);
		L(i, ml, mr) mx = max(mx, a[i]);
		L(i, 1, mx) cnt[i] = 0, f[i] = i;
		L(i, ml, mr) cnt[a[i]] ++;
		L(i, 1, m) if(opt[i] == 1) mdf(l[i], r[i], x[i]); else ans[i] += qry(l[i], r[i], x[i]); 
	}
	L(i, 1, m) if(opt[i] == 2) cout << ans[i] << "\n";
	return 0;
}