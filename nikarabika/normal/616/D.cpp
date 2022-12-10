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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 5e5 + 10;
vector<int> all;
int a[maxn], cnt[maxn];
int n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < n; i++)
		a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
	int q = 0, difcnt = 0, maxl = -1, maxr = -1;
	for(int i = 0; i < n; i++){
		if(i != 0){
			cnt[a[i - 1]]--;
			if(cnt[a[i - 1]] == 0)
				difcnt--;
		}
		while(q < n and (cnt[a[q]] != 0 or (cnt[a[q]] == 0 and difcnt < k))){
			cnt[a[q++]]++;
			if(cnt[a[q - 1]] == 1)
				difcnt++;
		}
		if(q - i > maxr - maxl)
			maxl = i, maxr = q;
	}
	cout << maxl + 1 << ' ' << maxr << endl;
	return 0;
}