#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
int n, m, a[N];
ll dpa[N], dpb[N], Ans;
struct node {
	int id, val;
} f[N];
bool cmp(node aa, node bb) {
	return aa.val == bb.val ? aa.id > bb.id : aa.val < bb.val;
}
struct BIT {
	ll val[N];
	void add(int x, int y) {
		for(int i = x; i <= n; i += (i & -i)) val[i] += y;
	}
	ll query(int x) {
		ll Ans = 0;
		for(int i = x; i; i -= (i & -i)) Ans += val[i];
		return Ans;
	}
} pa, pb;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] = 1e9 - a[i], f[i].id = i, f[i].val = a[i];
	sort(f + 1, f + n + 1, cmp);
	for(int i = 1; i <= n; i++) a[f[i].id] = i;
	for(int i = 1; i <= n; i++) {
		dpa[i] = pa.query(a[i]), dpb[i] = pb.query(a[i]);
		pb.add(a[i], dpa[i]), pa.add(a[i], 1);
		Ans += dpb[i];
	}
	printf("%lld\n", Ans);
	return 0;
}