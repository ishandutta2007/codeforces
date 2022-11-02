#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

// const int N = 

int T, n, s0, s1, s2, s3;

int main() {
	for(cin >> T; T--;) {
		scanf("%d%d%d%d", &s0, &s1, &s2, &s3);
		if(s0 > s2) swap(s0, s2), swap(s1, s3);
		puts(max(s0, s1) < min(s2, s3) ? "NO" : "YES");
	}
	return 0;
}