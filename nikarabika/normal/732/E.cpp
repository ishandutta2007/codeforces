//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const int maxn = 2e5 + 85 - 69;
int a[maxn],
	b[maxn],
	ans[maxn],
	cnt[maxn],
	mat[maxn],
	ansall, n, m;
set<pii> as, bs;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		b[i] = x;
		bs.insert(MP(x, i));
	}
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		a[i] = x;
		as.insert(MP(x, i));
	}
	memset(mat, -1, sizeof mat);
	while(sz(as)){
		pii x = *as.begin();
		as.erase(as.begin());
		auto it = bs.lower_bound(MP(x.L, -1));
		if(it == bs.end() or it->L != x.L){
			if(x.L != 1){
				x.L = (x.L + 1) >> 1;
				as.insert(x);
			}
		}
		else{
			mat[x.R] = it->R;
			bs.erase(it);
			ansall++;
		}
	}
	memset(ans, -1, sizeof ans);
	int sum = 0;
	for(int i = 0; i < m; i++)
		if(~mat[i]){
			while(a[i] != b[mat[i]])
				a[i] = (a[i]+1)>>1, cnt[i]++, sum++;
			ans[mat[i]] = i;
		}
	cout << ansall << ' ' << sum << '\n';
	for(int i = 0; i < m; i++)
		cout << cnt[i] << ' ';
	cout << '\n';
	for(int i = 0; i < n; i++)
		cout << ans[i]+1 << ' ';
	cout << '\n';
	return 0;
}