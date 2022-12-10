#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 85 - 69;
pie a[maxn];
vector<int> v[maxn], all;
int n;

void dfs(int x, int p = -1){
	cout << all[x] << ' ';
	for(int i = 0; i < v[x].size(); i++)
		if(v[x][i] != p)
			dfs(v[x][i], x);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].L >> a[i].R;
		all.PB(a[i].L);
		all.PB(a[i].R);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < n; i++){
		int id = lower_bound(all.begin(), all.end(), a[i].L) - all.begin(),
			id2 = lower_bound(all.begin(), all.end(), a[i].R) - all.begin();
		v[id].PB(id2);
		v[id2].PB(id);
	}
	for(int i = 0; i < all.size(); i++){
		if(v[i].size() == 1){
			dfs(i);
			cout << endl;
			return 0;
		}
	}
	return 0;
}