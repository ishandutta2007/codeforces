#include <bits/stdc++.h>
#define N 500000
#define int long long
#define inf (1LL << 60)
using namespace std;
 
int val[2001];
void solve(){
	int n, k, x;
	cin >> n >> k >> x;
	string s;
	cin >> s;
	vector<pair<int, int>> vi;
	int v = 0;
	int ca = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'a'){
			vi.push_back({v + 1, ca});
			v = 0;
			ca++;
		}else{
			v += k;
		}
	}
	vi.push_back({v + 1, ca});
	val[(int) vi.size()] = 1;
	for(int i = (int) vi.size() - 1; i >= 0; i--){
		val[i] = ((long double) val[i + 1] * vi[i].first > inf ? inf : val[i + 1] * vi[i].first);
	}
	int cca = 0;
	string ans = "";
	x--;
	for(int i = 0; i < vi.size(); i++){
		for(int j = cca; j < vi[i].second; j++) ans.push_back('a');
		cca = vi[i].second;
		if(val[i + 1] > x) continue;
		for(int j = 0; j < x / val[i + 1]; j++) ans.push_back('b');
		x %= val[i + 1];
	}
	cout << ans << endl;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}