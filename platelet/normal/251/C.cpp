#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 360360;
typedef long long ll;
int K, dis[N+5]; ll a, b, ans;
int main() {
	cin >> a >> b >> K;
	if(a / N > b / N) {
		mem(dis, 63), dis[0] = 0;
		For(i, 1, N) {
			dis[i] = dis[i-1] + 1;
			rep(j, 1, K) dis[i] = min(dis[i], dis[i/j*j] + 1);
		}
		ans = dis[a%N] + (dis[N-1] + 1LL) * (a / N - b / N - 1);
	}
	mem(dis, 63), dis[b%N] = 0;
	For(i, b % N + 1, N) {
		dis[i] = dis[i-1] + 1;
		rep(j, 1, K) dis[i] = min(dis[i], dis[i/j*j] + 1);
	}
	if(a / N == b / N) ans = dis[a%N]; else ans += dis[N-1] + 1;
	cout << ans;
	return 0;
}