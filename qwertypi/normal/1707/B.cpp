#include <bits/stdc++.h>
#define int long long
using namespace std;

priority_queue<pair<int, int>> pq;

const int MAXA = 5e5 + 13;
vector<int> a, b;
int n;

vector<int> cnt, cnt2;
vector<int> v, v2;

void solve(){
	cin >> n;
	a.resize(n); b.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; i++){
		if(!cnt[a[i + 1] - a[i]]) v.push_back(a[i + 1] - a[i]);
		cnt[a[i + 1] - a[i]]++;
	}
	while(v.size() != 1 || cnt[v[0]] != 1){
		sort(v.begin(), v.end());
//		cout << "*" << endl;
//		for(auto i : v){
//			cout << i << ' ' << cnt[i] << endl;
//		}
		for(int i = 0; i < v.size(); i++){
			if(cnt[v[i]] != 1 && cnt2[0] == 0) v2.push_back(0);
			cnt2[0] += cnt[v[i]] - 1;
		}
		for(int i = 0; i < (int) v.size() - 1; i++){
			if(cnt2[v[i + 1] - v[i]] == 0) v2.push_back(v[i + 1] - v[i]);
			cnt2[v[i + 1] - v[i]]++;
		}
		for(auto i : v) cnt[i] = 0;
		v.clear();
		swap(v, v2);
		swap(cnt, cnt2);
	}
	cnt[v[0]] = 0;
	v.clear();
	
	cout << v[0] << endl;
}

int32_t main(){
	cnt.resize(MAXA); cnt2.resize(MAXA);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}