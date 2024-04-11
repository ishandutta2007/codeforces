#include <bits/stdc++.h>

using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x;
		string s;
		cin >> n >> x >> s;
		int ttl = count(s.begin(), s.end(), '0') - count(s.begin(), s.end(), '1');
		map<int, int> cnt;
		int curCnt = 0;
		for(auto i : s){
			cnt[curCnt]++;
			if(i == '1'){
				curCnt--;
			}else{
				curCnt++;
			}
		}
		int ans = 0;
		if(ttl == 0){
			if(cnt[x] > 0){
				cout << -1 << endl;
			}else{
				cout << 0 << endl;
			}
		}else if(ttl > 0){
			for(auto i : cnt){
				if(i.first <= x && (i.first - x) % ttl == 0){
					ans += i.second; 
				}
			}
			cout << ans << endl;
		}else{
			for(auto i : cnt){
				if(i.first >= x && (i.first - x) % ttl == 0){
					ans += i.second; 
				}
			}
			cout << ans << endl;
		}
	}
}