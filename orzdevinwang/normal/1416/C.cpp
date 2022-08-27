#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
#define N 300010
#define M 9000010
#define ll long long
using namespace std;
int n, m, a[N], ch[M][2], dep[M], tot = 1;
vector<int> ve[M];
ll sum[33][2], ans;
void ins(int x, int y) {
	int now = 1;
	R(i, 30, 0) {
		bool tm = ((x >> i) & 1);
		if(!ch[now][tm]) ch[now][tm] = ++tot, dep[tot] = i;
		now = ch[now][tm], ve[now].push_back(y);
	}
}
int szsz[N];
void add(int x, int y) {
	for(int i = x; i <= n; i += (i & -i)) szsz[i] += y;
}
int query(int x) {
	int Ans = 0;
	for(int i = x; i; i -= (i & -i)) Ans += szsz[i];
	return Ans;
}
int la, lb, sa[N], sb[N];
void get(int x, int y) {
	int wz = dep[x];
	la = lb = 0;
	ll ansa = 0, ansb = 0;
	while(!ve[x].empty()) sa[++la] = ve[x].back(), ve[x].pop_back();
	while(!ve[y].empty()) sb[++lb] = ve[y].back(), ve[y].pop_back();
	L(i, 1, la) add(sa[i], 1);
	L(i, 1, lb) ansa += la - query(sb[i]);
	L(i, 1, la) add(sa[i], -1);
	sum[wz][0] += ansa;
	L(i, 1, lb) add(sb[i], 1);
	L(i, 1, la) ansb += lb - query(sa[i]);
	L(i, 1, lb) add(sb[i], -1);
	sum[wz][1] += ansb;
}
int px = 0;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ins(a[i], i);
	}
	for(int i = 1; i <= tot; i++) if(ch[i][0] && ch[i][1]) get(ch[i][0], ch[i][1]);
	L(i, 0, 30) {
		if(sum[i][0] <= sum[i][1]) ans += sum[i][0];
		else ans += sum[i][1], px += (1 << i);
	}
	printf("%lld %d\n", ans, px);
	return 0;
}