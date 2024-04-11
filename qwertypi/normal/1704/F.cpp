#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

struct ds{
	char major;
	int len;
};

const int N = 5e5 + 13;
int d[N];
int dp[N];
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt_r = 0, cnt_b = 0;
	for(auto i : s){
		cnt_r += i == 'R';
		cnt_b += i == 'B';
	}
	char c = 'X';
	int t = 0;
	
	for(int i = 0; i < n - 1; i++){
		if(s[i] != s[i + 1]){
			d[i] = true;
		}else{
			d[i] = false;
		}
	}
	vector<ds> vd;
	int l = 0;
	for(int i = 1; i < n; i++){
		if(!d[i - 1]){
			vd.push_back({s[l], i - l});
			l = i;
		}
	}
	vd.push_back({s[l], n - l});
	
	int xor_sum = 0;
	for(auto i : vd){
		xor_sum ^= dp[i.len];
	}
	if(xor_sum != 0) cnt_r++;
	if(cnt_r > cnt_b){
		cout << "Alice" << '\n';
	}else{
		cout << "Bob" << '\n';
	}
}

int mex(vector<int> v){
	map<int, int> M;
	for(auto i : v){
		M[i]++;
	}
	int t = 0;
	while(true){
		if(M.count(t) == 0){
			return t;
		}
		t++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for(int i = 2; i < 1000; i++){
		vector<int> v;
		for(int j = 0; j <= i - 2; j++){
			v.push_back(dp[j] ^ dp[i - j - 2]);
		}
		dp[i] = mex(v);
	}
	for(int i = 1000; i < N; i++){
		dp[i] = dp[i - 68];
	}
	
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
}