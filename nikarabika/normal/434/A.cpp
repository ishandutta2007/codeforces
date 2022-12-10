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

const int maxn = 1e5 + 85 - 69;
LL a[maxn];
vector<int> vec[maxn],
	cur;
LL sum;
int n, m;

int func(int id){
	int ret = 0;
	if(id + 1 < m) ret += abs(a[id] - a[id + 1]);
	if(id > 0) ret += abs(a[id] - a[id - 1]);
	return ret;
}

bool cmp(int i, int j){
	return a[i] < a[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a[i], a[i]--;
		if(i) sum += abs(a[i] - a[i - 1]);
		vec[a[i]].PB(i);
	}
	LL ans = sum;
	if(ans == 0){
		cout << ans << endl;
		return 0;
	}
	for(int i = 0; i < n; i++){
		cur.clear();
		LL cursum = sum;
		for(auto id : vec[i]){
			for(int j = -1; j <= +1; j++)
				if(id + j >= 0 and id + j < m and a[id + j] != i)
					cur.PB(id + j);
			cursum -= func(id);
		}
		sort(all(cur), cmp);
		LL ss = 0,
		   sss = 0;
		for(auto id : cur)
			ss += a[id];
		for(int j = 0; j < sz(cur); j++){
			int id = cur[j];
			ss -= a[id];
			sss += a[id];
			smin(ans, cursum + ss - sss + (j + 1) * a[id] - (sz(cur) - j - 1) * a[id]);
		}
	}
	cout << ans << endl;
	return 0;
}