#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int n, cnt, id[N], v[65], val; ll a[N], su;
bitset <N> bas[65], nw;
void ins(int x) {
	nw.reset();
	rep(i, 1, n) if(a[i] >> x & 1) nw[i] = 1;
	rep(i, 1, n) if(nw[i]) {
		if(id[i]) nw ^= bas[id[i]], val ^= v[id[i]];
		else {
			rep(j, i + 1, n) if(id[j] && nw[j]) nw ^= bas[id[j]], val ^= v[id[j]];
			rep(j, 1, i - 1) if(id[j] && bas[id[j]][i]) bas[id[j]] ^= nw, v[id[j]] ^= val;
			bas[id[i] = ++cnt] = nw, v[cnt] = val; break;
		}
	}
}
int main() {
	cin >> n;
	rep(i, 1, n) scanf("%lld", &a[i]), su ^= a[i];
	per(i, 59, 0) if(~su >> i & 1) val = 1, ins(i);
	per(i, 59, 0) if(su >> i & 1) val = 0, ins(i);
	rep(i, 1, n) printf("%d ", id[i] && v[id[i]] ? 1 : 2);
	return 0;
}