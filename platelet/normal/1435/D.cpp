#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define mid ((l + r) >> 1)
#define lch l, mid, o << 1
#define rch mid + 1, r, o << 1 | 1 

using namespace std;
const int N = 100005;
int n, cnt, x, tp, stk[N*2], ans[N*2], Min[N*2]; char op[2];
int main() {
	cin >> n;
	rep(i, 1, n * 2) {
		scanf("%s", op);
		if(op[0] == '+') stk[++tp] = ++cnt, Min[tp] = 0;
		else {
			if(!tp) return puts("NO"), 0;
			scanf("%d", &x);
			if(Min[tp] > x) return puts("NO"), 0;
			ans[stk[tp]] = x;
			tp--, Min[tp] = max(Min[tp], x + 1);
		}
	}
	if(tp) puts("NO");
	else {
		puts("YES");
		rep(i, 1, cnt) printf("%d ", ans[i]);
	}
}