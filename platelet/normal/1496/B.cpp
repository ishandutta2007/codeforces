#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;

int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	int T, n, K;
	for(cin >> T; T--;) {
		scanf("%d%d", &n, &K);
		set <int> s;
		int x, mex = 0, ans = 0;
		rep(i, 1, n) scanf("%d", &x), s.insert(x);
		while(s.count(mex)) mex++;
		while(K) {
			int nw = (mex + *s.rbegin() + 1) / 2;
			if(nw == mex) break;
			if(s.count(nw)) K = 0;
			else {
				s.insert(nw);
				while(s.count(mex)) mex++;
				K--;
			}
		}
		cout << s.size() + K << endl;
	}
	return 0;
}