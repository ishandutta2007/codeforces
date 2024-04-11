#include <bits/stdc++.h>
#define inf (1LL << 60)
#define int long long
using namespace std;

int f[100];
int ans[100001];
bool chosen[100001];
void solve(){
	int n, k;
	cin >> n >> k; k--;
	for(int i = 0; i < n; i++){
		ans[i] = i + 1;
	}
	fill(chosen, chosen + n + 1, false);
	for(int i = max(1LL, n - 60); i < n; i++){
		int p = n - i - 1;
		if(k >= (1LL << p)){
			k -= (1LL << p);
			// cout << "chosen " << i << endl;
			chosen[i] = true;
		}
	}
	
	if(k){
		cout << -1 << endl;
		return;
	}
	
	vector<int> ct;
	for(int i = 0; i < n; i++){
		if(!chosen[i + 1]){
			cout << i + 1 << ' ';
			while(ct.size()){
				cout << ct.back() << ' ';
				ct.pop_back();
			}
		}else{
			ct.push_back(i + 1);
		}
	}
	while(ct.size()){
		cout << ct.back() << ' ';
		ct.pop_back();
	}
	cout << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--) solve();	
}