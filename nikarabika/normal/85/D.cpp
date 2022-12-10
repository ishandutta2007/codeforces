#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 1e5 + 85 - 69;
int seg[maxn * 4];
LL sum[maxn * 4][5];
vector<LL> all;
int n;

void change(int idx, int l = 0, int r = sz(all), int id = 1){
	if(idx < l or r <= idx)
		return;
	if(r - l == 1){
		seg[id] = 1 - seg[id];
		sum[id][1] = seg[id] * all[idx];
		return;
	}
	int mid = (l + r) >> 1;
	change(idx, l, mid, id * 2 + 0);
	change(idx, mid, r, id * 2 + 1);
	seg[id] = seg[id * 2 + 0] + seg[id * 2 + 1];
	for(int i = 0; i < 5; i++)
		sum[id][i] = sum[id * 2 + 0][i] + sum[id * 2 + 1][(((i - seg[id * 2 + 0]) % 5) + 5) % 5];
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	stringstream ss;
	for(int i = 0; i < n; i++){
		string tp;
		int val;
		cin >> tp;
		if(tp == "sum"){
			ss << tp << '\n';
			continue;
		}
		cin >> val;
		ss << tp << ' ' << val << '\n';
		all.PB(val);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < n; i++){
		string tp;
		LL val;
		ss >> tp;
		if(tp == "sum"){
			cout << sum[1][3] << '\n';
			continue;
		}
		ss >> val;
		int id = lower_bound(all.begin(), all.end(), val) - all.begin();
		change(id);
	}
	return 0;
}