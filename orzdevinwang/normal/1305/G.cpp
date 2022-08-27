#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 3e5 + 7;
int n, a[N], f[N], cnt[N];
ll sum, ans;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]), cnt[a[i]] ++, sum += a[i];
	L(i, 1, 262143) f[i] = i;
	cnt[0]++;
	R(i, 262143, 1) 
		for(int j = i; j; j = ((j - 1) & i)) {
			while(cnt[i ^ j] && cnt[j] && find(j) != find(i ^ j)) 
				f[find(j)] = find(i ^ j), ans += 1ll * i * (cnt[j] + cnt[i ^ j] - 1), cnt[j] = cnt[i ^ j] = 1;
			if(j == 0) break;
		}
			
	printf("%lld\n", ans - sum);
	return 0;
}