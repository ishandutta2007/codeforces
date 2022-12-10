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

const int maxn = 1e5 + 85 - 69,
	  maxval = 1 << 21,
	  maxl = 20;
int cnt[maxval],
	spt[maxl][maxn],
	pp[maxn],
	n;

int get(int st, int en){
	int f = pp[en - st + 1];
	return spt[f][st] | spt[f][en - (1 << f) + 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> spt[0][i];
	pp[0] = -1;
	for(int i = 1; i < maxn; i++) pp[i] = pp[i>>1]+1;
	for(int i = 1; i < maxl; i++)
		for(int j = 0; j + (1 << i) <= n; j++)
			spt[i][j] = spt[i - 1][j] | spt[i - 1][j + (1 << (i - 1))];
	for(int i = 0; i < n; i++){
		int pos = i;
		int cur = spt[0][i];
		while(pos < n){
			cnt[cur]++;
			int lo = pos, hi = n;
			while(hi - lo > 1){
				int mid = (lo + hi) >> 1;
				if(get(i, mid) == cur)
					lo = mid;
				else
					hi = mid;
			}
			cur = get(i, pos = hi);
		}
	}
	int ans = 0;
	for(int i = 0; i < maxval; i++)
		ans += bool(cnt[i]);
	cout << ans << '\n';
	return 0;
}