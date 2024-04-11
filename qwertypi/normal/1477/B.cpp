#include <bits/stdc++.h>

using namespace std;

int n, q;

bool A[200001];
set<pair<int, int>> S;

void upd(int l, int r, int val){
	/*cout << "upd: " << l << ' ' << r << ' ' << val << endl;
	for(auto i : S){
		cout << i.first << ' ' << i.second << endl;
	}*/
	auto ptr_l = S.lower_bound(make_pair(l, -1));
	auto ptr_r = S.lower_bound(make_pair(r + 1, -1));
	// cout << "l: " << ptr_l->first << ' ' << ptr_l->second << endl;
	// cout << "r: " << ptr_r->first << ' ' << ptr_r->second << endl;
	auto last = ptr_r; last--; int last_val = last->second;
	vector<pair<int, int>> vals;
	for(auto ptr = ptr_l; ptr != ptr_r; ptr++){
		vals.push_back(*ptr);
	}
	for(auto i : vals) S.erase(i);
	S.insert({l, val});
	if(S.lower_bound({r + 1, -1})->first != r + 1) S.insert({r + 1, last_val});
}

int qry(int l, int r){
	/*cout << "qry: " << l << ' ' << r << ' ' << endl;
	for(auto i : S){
		cout << i.first << ' ' << i.second << endl;
	}*/
	auto ptr_l = S.lower_bound(make_pair(l, 1 << 30)); ptr_l--;
	auto ptr_r = S.lower_bound(make_pair(r + 1, -1));
	int res = 0;
	vector<pair<int, int>> data;
	for(auto ptr = ptr_l; ptr != ptr_r; ptr++){
		data.push_back(*ptr);
	}
	data.push_back(*ptr_r);
	for(int i = 0; i < data.size() - 1; i++){
		// cout << l << ' ' << r << ' ' << data[i].first << ' ' << data[i + 1].first << ' ' << data[i].second << endl;
		// cout << min(r, data[i + 1].first - 1) << ' ' << max(l, data[i].first) << ' ' << data[i].second << endl;
		res += (min(r, data[i + 1].first - 1) - max(l, data[i].first) + 1) * data[i].second;
	}
	// cout << res << endl;
	return res;
}

void solve(){
	S.clear();
	cin >> n >> q;
	string s, f;
	cin >> s >> f;
	for(int i = 0; i < n; i++){
		S.insert({i, f[i] == '1'});
	}
	S.insert({-1, -1});
	S.insert({n, -1});
	vector<pair<int, int>> vip;
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r; l--; r--;
		vip.push_back({l, r});
	}
	// How come this is greedy???
	
	for(int i = q - 1; i >= 0; i--){
		int l = vip[i].first, r = vip[i].second;
		int cnt = qry(l, r);
		int ttl = (r - l + 1);
		if(cnt <= (ttl - 1) / 2){
			upd(l, r, 0);
		}else if(ttl - cnt <= (ttl - 1) / 2){
			upd(l, r, 1);
		}else{
			cout << "NO" << endl;
			return;
		}
	}
	
	string ans;
	int idx = 0, _p = -1;
	for(auto i : S){
		if(i.first == -1) continue;
		for(int j = idx; j < i.first; j++){
			ans.push_back('0' + _p);
		}
		_p = i.second; idx = i.first;
	}
	// cout << ans << endl;
	cout << (ans == s ? "YES" : "NO") << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}