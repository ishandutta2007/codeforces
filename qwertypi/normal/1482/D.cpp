#include <bits/stdc++.h>

using namespace std;

int A[100001];
vector<pair<int, int>> cnt;

int dp[100001][3];
int query(int l, int r, int lval, int rval){
	if(lval != rval || lval == 0 || rval == 0) return r - l + 1;
	vector<bool> ok;
	for(int i = l; i <= r; i++){
		ok.push_back(cnt[i].first == lval);
	}
	for(int i = 0; i < (int) ok.size() - 1; i++){
		if(ok[i] == ok[i + 1]) return r - l + 1;
	}
	return r - l;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	cnt.push_back({0, 2});
	cnt.push_back({A[0], 1});
	for(int i = 1; i < n; i++){
		if(A[i] == cnt.back().first){
			cnt.back().second = min(cnt.back().second + 1, 2);
		}else{
			cnt.push_back({A[i], 1});
		}
	}
	cnt.push_back({0, 2});
	
	int cnt2 = 0;
	for(auto i : cnt) cnt2 += i.second == 2;
	cnt2 -= 2;
	vector<int> B;
	for(int i = 0; i < (int) cnt.size(); i++) if(cnt[i].second == 2) B.push_back(i);
	int ans = 0;
	for(int i = 0; i < (int) B.size() - 1; i++){
		ans += query(B[i] + 1, B[i + 1] - 1, cnt[B[i]].first, cnt[B[i + 1]].first);
	}
	ans += cnt2 * 2;
	cout << ans << endl; 
}