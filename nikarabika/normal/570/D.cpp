#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 5e5 + 85 - 69;
vector<int> sttimes[maxn], ch[maxn];
int par[maxn], h[maxn], st[maxn], ft[maxn];
vector<vector<int> > vects[maxn];
int n, q, dfs_time;
char c[maxn];
vector<int> empty_counter;

void dfs(int x){
	st[x] = ++dfs_time;
	if(!sz(sttimes[h[x]])){
		vects[h[x]].PB(empty_counter);
		sttimes[h[x]].PB(-1);
	}
	vects[h[x]].PB(vects[h[x]].back());
	vects[h[x]][sz(vects[h[x]]) - 1][c[x] - 'a']++;
	sttimes[h[x]].PB(st[x]);
	for(int i = 0; i < sz(ch[x]); i++){
		h[ch[x][i]] = h[x] + 1;
		dfs(ch[x][i]);
	}
	ft[x] = dfs_time;
}

bool ispal(int hei, int stime, int ftime){
	if(!sz(sttimes[hei]))
		return true;
	int id1 = lower_bound(sttimes[hei].begin(), sttimes[hei].end(), stime) - sttimes[hei].begin(),
		id2 = upper_bound(sttimes[hei].begin(), sttimes[hei].end(), ftime) - sttimes[hei].begin();
	id1--, id2--;
	int odd = 0;
	for(int i = 0; i < 26; i++)
		odd += (vects[hei][id1][i] + vects[hei][id2][i]) & 1;
	return odd <= 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < 26; i++)
		empty_counter.PB(0);
	cin >> n >> q;
	for(int i = 2; i <= n; i++){
		cin >> par[i];
		ch[par[i]].PB(i);
	}
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	dfs(1);
	/*for(int i = 0; i < n; i++){
		cout << i << ": ";
		for(int j = 0; j < sttimes[i].size(); j++)
			cout << sttimes[i][j] << ' ';
		cout << endl;
	}*/
	while(q--){
		int fi, se;
		cin >> fi >> se;
		se--;
		if(se < h[fi] or ispal(se, st[fi], ft[fi]))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}