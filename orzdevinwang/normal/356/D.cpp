// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define uint unsigned int
using namespace std;
const int N = 7e4 + 7;
const int B = 300;
bitset<N> bs, Gs[B + 10], ns[B + 10];
int n, m, dy[N], vis[N], cnt[N], GM[N];
struct node {
	int val, id;
} a[N];
bool cmp(node aa, node bb) {
	return aa.val > bb.val;
}
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n) scanf("%d", &a[i].val), a[i].id = i;
	sort(a + 1, a + n + 1, cmp);
	L(i, 1, n) dy[a[i].id] = i, cnt[i] = a[i].val;
	// L(i, 1, n) cout << a[i].val << " ";
	// puts("");
	bs.set(a[1].val);
	int cntB = 1;
	L(i, 2, n) {
		bs |= (bs << a[i].val);
		if(i % B == 0) Gs[i / B] = bs, cntB ++;
	}
	if(bs[m] == 0) return puts("-1"), 0;
	int now = m;
	R(i, cntB, 1) {
		int L = (i - 1) * B;
		ns[0] = Gs[i - 1];
		ns[1].reset();
		if(i == 1) ns[1][a[1].val] = 1;
		L(j, (i == 1 ? 2 : 1), min(n - L, B)) ns[j] = (ns[j - 1] | (ns[j - 1] << a[L + j].val));
		// if(i == 1) cout << now << " = " << ns[B - 2][now - 2] << endl;
		R(j, min(n - L, B), (i == 1 ? 2 : 1)) if(ns[j - 1][now - a[L + j].val]) vis[L + j] = 1, now -= a[L + j].val;
		// if(i == 1) cout << (ns[B] == Gs[1]) << endl;
	}
	int las = 1;
	L(i, 2, n) if(!vis[i]) cnt[las] -= a[i].val, GM[las] = i, las = i;
	// L(i, 1, n) cout << vis[i] << " ";
	// puts("");
	L(i, 1, n) {
		printf("%d", cnt[dy[i]]);
		if(GM[dy[i]]) printf(" 1 %d\n", a[GM[dy[i]]].id);
		else printf(" 0\n");
	}
	return 0;
}