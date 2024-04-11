#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		string s[3];
		for(int i = 0; i < 3; i++) cin >> s[i];
		int cnt[3] = {0, 0, 0};
		for(int i = 0; i < n * 2; i++) cnt[0] += s[0][i] == '1';
		for(int i = 0; i < n * 2; i++) cnt[1] += s[1][i] == '1';
		for(int i = 0; i < n * 2; i++) cnt[2] += s[2][i] == '1';
		for(int i = 0; i < 3; i++){
			if(cnt[i] >= n && cnt[(i + 1) % 3] >= n){
				int j = (i + 1) % 3;
				string ans;
				int idx_0 = 0, idx_1 = 0;
				while(idx_0 + idx_1 != n * 4){
					if(idx_1 == n * 2 || s[i][idx_0] == '0') ans.push_back(s[i][idx_0++]);
					else if(idx_0 == n * 2 || s[j][idx_1] == '0') ans.push_back(s[j][idx_1++]);
					else if(idx_0 != n * 2 && idx_1 != n * 2 && s[i][idx_0] == '1' && s[j][idx_1] == '1') ans.push_back('1'), idx_0++, idx_1++;
				}
				cout << ans << endl;
				break;
			}
			if(cnt[i] <= n && cnt[(i + 1) % 3] <= n){
				int j = (i + 1) % 3;
				string ans;
				int idx_0 = 0, idx_1 = 0;
				while(idx_0 + idx_1 != n * 4){
					if(idx_1 == n * 2 || s[i][idx_0] == '1') ans.push_back(s[i][idx_0++]);
					else if(idx_0 == n * 2 || s[j][idx_1] == '1') ans.push_back(s[j][idx_1++]);
					else if(idx_0 != n * 2 && idx_1 != n * 2 && s[i][idx_0] == '0' && s[j][idx_1] == '0') ans.push_back('0'), idx_0++, idx_1++;
				}
				cout << ans << endl;
				break;
			}
		}
	}
}