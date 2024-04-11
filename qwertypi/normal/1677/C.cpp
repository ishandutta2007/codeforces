#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 13;
int A[N], B[N], p[N];
bool vis[N];
void solve(){
	int n;
	cin >> n;
	fill(vis, vis + n + 1, 0); 
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		cin >> B[i];
	}
	for(int i = 0; i < n; i++) p[A[i]] = B[i];
	vector<int> cyc;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			vis[i] = true;
			int x = p[i], l = 1;
			while(x != i){
				vis[x] = true, l++, x = p[x];
			}
			cyc.push_back(l);
		}
	}
	int cnt = 0;
	for(auto i : cyc) cnt += (i - i % 2) / 2;
	long long ans = 0;
	for(int i = 1; i <= cnt; i++) ans -= i, ans += n + 1 - i;
	cout << ans * 2 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}