#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int long long 
int f(int x){
	return x * (x + 1) / 2;
}
 
vector<pair<string, int>> ans;
void sub(){
	int n, m, k;
	cin >> n >> m >> k;
	if(k > 4 * n * m - 2 * n - 2 * m){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	int cnt = k;
	for(int i = 0; i < n && cnt > 0; i++){
		if(i >= 1){
			ans.push_back({"D", 1});
			cnt--;
		}
		if(i == 0){
			if(cnt >= m - 1){
				ans.push_back({"R", m - 1});
				cnt -= m - 1;
			}else{
				ans.push_back({"R", cnt});
				goto End;
			}
	
			if(cnt >= m - 1){
				ans.push_back({"L", m - 1});
				cnt -= m - 1;
			}else{
				ans.push_back({"L", cnt});
				goto End;
			}
		}else{
			if(cnt >= m - 1){
				ans.push_back({"R", m - 1});
				cnt -= m - 1;
			}else{
				ans.push_back({"R", cnt});
				goto End;
			}
	
			if(cnt >= 3 * m - 3){
				ans.push_back({"UDL", m - 1});
				cnt -= 3 * m - 3;
			}else{
				if(cnt >= 3){
					ans.push_back({"UDL", cnt / 3});
				}
				if(cnt % 3 == 1){
					ans.push_back({"U", 1});
				}
				if(cnt % 3 == 2){
					ans.push_back({"UD", 1});
				}
				goto End;
			}
		}
	}
	if(cnt != 0){
		ans.push_back({"U", cnt});
	}
	End:
		int _cnt = 0;
		for(auto i : ans){
			if(i.second != 0){
				_cnt++;
			}
		}
	cout << _cnt << endl;
	for(auto i : ans){
		if(i.second != 0)
			cout << i.second << ' ' << i.first << endl;
	}
}
 
int32_t main(){
	int t = 1;
	while(t--){
		sub();
	}
}