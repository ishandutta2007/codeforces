#include <bits/stdc++.h>

using namespace std;

int n;
int reg(int x){
	if(x >= n) return x - n;
	if(x < 0) return x + n;
	return x;
}

int query(int t, int i, int j, int x){
	cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl; 
	int res;
	cin >> res;
	return res;
}

int ans[10001];

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int v = -1;
		set<int> to_check;
		for(int i = 0; i < n; i += 2){
			int res = query(2, reg(i), reg(i + 1), 1);
			if(res == 1 || res == 2){
				to_check.insert(reg(i));
				to_check.insert(reg(i + 1));
			}
		}
		
		vector<int> vi(to_check.begin(), to_check.end());
		
//		for(auto i : vi){
//			cout << i << ' ';
//		}
//		cout << endl;
		
		for(int i = 0; i < (int) vi.size(); i++){
			for(int j = 0; j < (int) vi.size(); j++){
				if(i != j){
					int res = query(2, vi[i], vi[j], 1);
					if(res == 1){
						v = vi[i];
					}
				}
			}
		}
		ans[v] = 1;
		for(int i = 0; i < n; i++){
			if(i != v){
				ans[i] = query(1, v, i, n - 1);
			}
		}
		cout << "! ";
		for(int i = 0; i < n; i++){
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}