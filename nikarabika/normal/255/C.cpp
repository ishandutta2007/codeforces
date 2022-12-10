#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 4e3 + 85 - 69;
vector<int> v[maxn], all;
int a[maxn], ans;
int n;

int solve(int x, int y){
	if(v[x][0] > v[y][0])
		swap(x, y);
	int ret = 2;
	int p = 0, q = 0;
	while(p < v[x].size() and q < v[y].size()){
		while(p < v[x].size() and v[x][p] < v[y][q]) p++;
		if(p != v[x].size())
			ret++;
		else
			break;
		while(q < v[y].size() and v[y][q] < v[x][p]) q++;
		if(q != v[y].size())
			ret++;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], all.PB(a[i]);
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 1; i <= n; i++){
		int id = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
		v[id].PB(i);
		ans = max(ans, (int)v[id].size());
	}
	for(int i = 0; i < all.size(); i++)
		for(int j = i + 1; j < all.size(); j++)
			ans = max(ans, solve(i, j));
	cout << ans << endl;
	return 0;
}