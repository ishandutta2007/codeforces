#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
using namespace std;
const int N = 1e5 + 7;
const int B = 320;
int n, m, q, siz[N], tot, vis[N], bh[B + 10];
vector<int> S[N];
char opt[5];
int Cnt[N][B + 10];
ll YS[B + 10], Lazy[B + 10], a[N];
bool used[N];
int main() {
	scanf("%d%d%d", &n, &m, &q);
	L(i, 1, n) scanf("%lld", &a[i]);
	L(i, 1, m) {
		scanf("%d", &siz[i]);
		if(siz[i] > B) vis[i] = ++tot, bh[tot] = i;
		L(j, 1, siz[i]) {
			int k; scanf("%d", &k);
			if(siz[i] > B) YS[tot] += a[k]; // (YS[tot] += George1123)
			S[i].push_back(k);
		}
	}
	L(i, 1, tot) {
		for(int x : S[bh[i]]) used[x] = 1;
		L(j, 1, m) for(int x : S[j]) Cnt[j][i] += used[x]; 
		for(int x : S[bh[i]]) used[x] = 0;
	} 
	while(q--) {
		scanf("%s", opt);
		if(opt[0] == '+') {
			int x, y; scanf("%d%d", &x, &y);
			L(i, 1, tot) YS[i] += 1ll * y * Cnt[x][i];
			if(siz[x] <= B) for(int t : S[x]) a[t] += y;
			else Lazy[vis[x]] += y;
		}
		else {
			int x; scanf("%d", &x);
			ll sum = 0;
			if(siz[x] <= B) {
				L(i, 1, tot) sum += 1ll * Cnt[x][i] * Lazy[i];
				for(int t : S[x]) sum += a[t];
			}
			else sum += YS[vis[x]];
			printf("%lld\n", sum);
		}
	}
	return 0;
}