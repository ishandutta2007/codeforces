#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)
#define mod 1000000007
using namespace std;

string ans;
int32_t main(){
	ans.resize(300010);
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end(), [](char a, char b){
		return a > b;
	});
	
	int n = s.size();
	s.resize(n % 2 + n / 2);
	t.resize(n / 2);
	int l = 0, r = 0, L_idx = 0, R_idx = n - 1;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0){ // small
			if(s[l] >= t[r]){
				ans[R_idx--] = s.back();
				s.pop_back();
			}else{
				ans[L_idx++] = s[l]; l++;
			}
		}else{
			if(s[l] >= t[r]){
				ans[R_idx--] = t.back();
				t.pop_back();
			}else{
				ans[L_idx++] = t[r]; r++;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i];
	}
	cout << '\n';
}