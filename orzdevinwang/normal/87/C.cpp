#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, SG[N], ans[N], a[N];
vector<int> ve[N];
int main() {
	scanf("%d", &n);
	fill(ans + 1, ans + n + 1, 1e9);
	SG[1] = 0;
	L(i, 2, n) {
		sort(ve[i].begin(), ve[i].end());
		for(int x : ve[i]) if(x == SG[i]) SG[i] = x + 1;
		int sum = i, now = SG[i];
		R(j, i - 1, 1) {
			sum += j, now ^= SG[j];
			if(sum > n) break;
			ve[sum].push_back(now);
			if(now == 0) ans[sum] = min(ans[sum], i - j + 1);
		}
	}
	if(!SG[n]) puts("-1");
	else printf("%d\n", ans[n]);
	return 0;
}