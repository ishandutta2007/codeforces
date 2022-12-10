#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef long long int LL;
typedef pair<int, int> pie;
typedef pair<pie, int> piie;

const int maxn = 1e5 + 85 - 85 + 1;
int cnt[maxn];
int a[maxn];
vector<int> all;
vector<piie> in;
int n, m, ans[maxn];

bool cmp(piie x, piie y){
	if(x.L.R < y.L.R)
		return true;
	if(x.L.R > y.L.R)
		return false;
	return x.L.L < y.L.L;
}

void solve(int l, int r){
	if(l >= r)
		return;
	memset(cnt, 0, sizeof cnt);
	sort(in.begin() + l, in.begin() + r, cmp);
	int s = in[l].L.L;
	int e = in[l].L.L;
	int an = 0;
	while(e <= in[l].L.R){
		int id = lower_bound(all.begin(), all.end(), a[e]) - all.begin();
		an -= cnt[id] == all[id];
		cnt[id]++;
		an += cnt[id] == all[id];
		e++;
	}
	ans[in[l].R] = an;
	for(int i = l + 1; i < r; i++){
		while(e <= in[i].L.R){
			int id = lower_bound(all.begin(), all.end(), a[e]) - all.begin();
			an -= cnt[id] == all[id];
			cnt[id]++;
			an += cnt[id] == all[id];
			e++;
		}
		while(s > in[i].L.L){
			s--;
			int id = lower_bound(all.begin(), all.end(), a[s]) - all.begin();
			an -= cnt[id] == all[id];
			cnt[id]++;
			an += cnt[id] == all[id];
		}
		while(s < in[i].L.L){
			int id = lower_bound(all.begin(), all.end(), a[s]) - all.begin();
			an -= cnt[id] == all[id];
			cnt[id]--;
			an += cnt[id] == all[id];
			s++;
		}
		ans[in[i].R] = an;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		in.PB(MP(MP(fi - 1, se - 1), i));
	}
	sort(in.begin(), in.end());
	int l = sqrt(n);
	int p = 0, q = 0;
	for(int i = 0; p < m; i++){
		int st = i * l, en = (i + 1) * l;
		while(q < m and in[q].L.L < en)
			q++;
		while(p < m and in[p].L.L < st)
			p++;
		solve(p, q);
	}
	
	for(int i = 0; i < m; i++)
		cout << ans[i] << ' ';
	cout << endl;
	
	return 0;
}