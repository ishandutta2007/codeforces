#include <bits/stdc++.h>

using namespace std;

int A[300001];
int s[300001];
int Is[300001];
void solve(){
	int n, q;
	cin >> n >> q;
	string S;
	cin >> S;
	for(int i = 0; i < n; i++){
		A[i] = (S[i] == '+' ? 1 : -1);
	}
	for(int i = 0; i < n; i++){
		s[i + 1] = s[i] + A[i];
		Is[i + 1] = Is[i] + (i % 2 ? -1 : 1) * A[i];
	}
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		if(Is[r] == Is[l - 1]){
			cout << 0 << endl;
			continue;
		}
		vector<int> ans;
		if((Is[r] - Is[l - 1]) % 2 == 0){
			ans.push_back(r);
			r--;
		}
		int L = l, R = r;
		int lval = -(Is[r] - Is[l]), rval = (Is[r - 1] - Is[l - 1]);
		while(L + 1 < R){
			int m = (L + R) / 2;
			int v = (Is[m - 1] - Is[l - 1]) - (Is[r] - Is[m]);
			if(v <= 0 && 0 <= lval || lval <= 0 && 0 <= v){
				R = m;
			}else{
				L = m;
			}
		}
		if((Is[L - 1] - Is[l - 1]) - (Is[r] - Is[L]) == 0){
			ans.push_back(L);
		}else if((Is[R - 1] - Is[l - 1]) - (Is[r] - Is[R]) == 0){
			ans.push_back(R);
		}else{
			assert(1 == 0);
		}
		sort(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for(auto i : ans) cout << i << ' ';
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}