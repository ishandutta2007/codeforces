#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct node { int id, x, y, z, ans, aans; } a[N << 1];
bool cmpx(node aa, node bb) { return aa.x == bb.x ? (aa.y == bb.y ? aa.z < bb.z : aa.y < bb.y) : aa.x < bb.x; }
bool cmpy(node aa, node bb) { return aa.y == bb.y ? (aa.x == bb.x ? aa.z < bb.z : aa.x < bb.x) : aa.y < bb.y; }
bool cmpz(node aa, node bb) { return aa.z == bb.z ? (aa.x == bb.x ? aa.y < bb.y : aa.x < bb.x) : aa.z < bb.z; }
bool cmpg(node aa, node bb) { return aa.x == bb.x ? (aa.y == bb.y ? (aa.z == bb.z ? aa.ans > bb.ans : aa.z < bb.z) : aa.y < bb.y) : aa.x < bb.x; }
bool cmpp(node aa, node bb) { return aa.x == bb.x ? (aa.y == bb.y ? (aa.z == bb.z ? aa.aans > bb.aans : aa.z < bb.z) : aa.y < bb.y) : aa.x < bb.x; }
bool cmpd(node aa, node bb) { return aa.id < bb.id; }
int szsz[N << 1];
void add(int x, int y) { if(!x) return;for(int i = x; i <= 200000; i += (i & -i)) szsz[i] += y; }
int query(int x) { int Ans = 0; for(int i = x; i; i -= (i & -i)) Ans += szsz[i]; return Ans; }
void lsh(node *f, int len) { //  
	int las, qwq;
	sort(f + 1, f + len + 1, cmpx);
	for(int i = 1; i <= len; i++) qwq = las, las = f[i].x, f[i].x = (f[i - 1].x + (qwq != f[i].x));
	sort(f + 1, f + len + 1, cmpy);
	for(int i = 1; i <= len; i++) qwq = las, las = f[i].y, f[i].y = (f[i - 1].y + (qwq != f[i].y));
	sort(f + 1, f + len + 1, cmpz);
	for(int i = 1; i <= len; i++) qwq = las, las = f[i].z, f[i].z = (f[i - 1].z + (qwq != f[i].z));
}
void cdq(node *f, int len, bool flag) {
	if(len == 1) return;
	int mid = (len + 1) / 2, now = mid + 1;
	sort(f + 1, f + len + 1, cmpx);
	sort(f + 1, f + mid + 1, cmpy);
	sort(f + mid + 1, f + len + 1, cmpy);
	for(int i = 1; i <= mid; i++) {
		while(now <= len && f[now].y < f[i].y) f[now].ans += query(f[now].z) * flag, f[now].aans += query(f[now].z) * (flag ^ 1), ++now;
		add(f[i].z, 1);
	}
	while(now <= len) f[now].ans += query(f[now].z) * flag, f[now].aans += query(f[now].z) * (flag ^ 1), ++now;
	for(int i = 1; i <= mid; i++) add(f[i].z, -1);
	cdq(f, mid, flag), cdq(f + mid, len - mid, flag);
}
int n, m, p[N], s[N], b[N], inc[N], pref[N], cnt[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++) a[i].x = p[i] - b[i], a[i].y = b[i] + p[i], a[i].z = -s[i];
	for(int i = 1; i <= m; i++) scanf("%d", &inc[i]);
	for(int i = 1; i <= m; i++) scanf("%d", &pref[i]);
	for(int i = 1; i <= m; i++) a[i + n].x = inc[i] - pref[i], a[i + n].y = pref[i] + inc[i], a[i + n].z = -inc[i];
	for(int i = 1; i <= n + m; i++) a[i].id = i;
	lsh(a, n + m);
	cdq(a, n + m, 1);
	sort(a + 1, a + n + m + 1, cmpg); 
	for(int i = 1; i <= n + m; i++) if(a[i].x == a[i - 1].x && a[i].y == a[i - 1].y && a[i].z == a[i - 1].z) a[i].ans = a[i - 1].ans;
	sort(a + 1, a + n + m + 1, cmpd);
	cdq(a + n, m, 0);
	sort(a + n + 1, a + n + m + 1, cmpp);
	for(int i = 1; i <= n + m; i++) if(a[i].x == a[i - 1].x && a[i].y == a[i - 1].y && a[i].z == a[i - 1].z) a[i].aans = a[i - 1].aans;
	sort(a + 1, a + n + m + 1, cmpd);
	for(int i = n + 1; i <= n + m; i++) printf("%d ", a[i].ans - a[i].aans);
	return 0;
}