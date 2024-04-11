#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e5 + 10;
int fen[maxn * 2];
int n;
int cnt[maxn], a[maxn];
vector<int> v, ans;

int MIN(int id){
	int ret = 2e9;
	while(id > 0){
		ret = min(ret, fen[id]);
		id -= id & (-id);
	}
	return ret;
}

void upd(int id, int val){
	id++;
	while(id <= n){
		fen[id] = min(fen[id], val);
		id += id & (-id);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(fen, 127, sizeof fen);
	memset(cnt, 127, sizeof cnt);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		v.PB(a[i]);
	}
	reverse(a, a + n);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for(int i = 0; i < n; i++){
		int id = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		int x = MIN(id);
		if(x > 1e9)
			ans.PB(-1);
		else
			ans.PB(i - x - 1);
		if(cnt[id] > 1e9){
			cnt[id] = i;
			upd(id, i);
		}
	}
	for(int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';
	cout << endl;

	return 0;
}