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

const int maxn = 3e5 + 85 - 69,
	  maxval = 1000 * 1000 + 85 - 69,
	  maxlen = 2000 * 1000 + 85 - 69;
int a[maxn],
	cnt[maxlen],
	n, k;

int get(int l, int r){
	r++;
	smin(r, maxlen - 1);
	return cnt[r] - cnt[l];
}

bool check(int val){
	int ret = 0;
	for(int i = val; i < maxval; i += val)
		ret += get(i, min(i + val - 1, i + k));
	return ret == n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]+1]++;
	}
	sort(a, a + n);
	for(int i = 0; i + 1 < maxlen; i++)
		cnt[i + 1] += cnt[i];
	int ans = 1;
	for(int i = a[0]; i > 0; --i)
		if(check(i))
			smax(ans, i);
	cout << ans << '\n';
	return 0;
}