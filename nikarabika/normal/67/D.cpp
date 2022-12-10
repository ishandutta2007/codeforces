//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1000 * 1000;
int a[maxn], pos[maxn], dp[maxn], siz;
int n;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		x--;
		pos[x] = i;
	}
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		a[i] = pos[a[i] - 1];
	}
	reverse(a, a + n);
	for(int i = 0; i < n; i++){
		int id = lower_bound(dp, dp + siz, a[i]) - dp;
		dp[id] = a[i];
		smax(siz, id + 1);
	}
	printf("%d", siz);
	return 0;
}