#include <bits/stdc++.h>

using namespace std;

int method = 0;
vector<int> ans;
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cout << "? " << i << ' ' << 1 << ' ' << i << ' ' << n << endl;
		int v; cin >> v;
		if(v % 2) method = 1, ans.push_back(i); 
	}
	if(method != 0) goto End;
	for(int i = 1; i < n; i++){
		cout << "? " << 1 << ' ' << i << ' ' << n << ' ' << i << endl;
		int v; cin >> v;
		if(v % 2) method = 2, ans.push_back(i);
	}
	if(ans.size() == 1) ans.push_back(n);
	End:;
	if(method == 1){
		vector<pair<int, int>> points;
		for(int k = 0; k < 2; k++){
			int l = 1, r = n;
			while(l != r){
				int m = (l + r) >> 1;
				cout << "? " << ans[k] << ' ' << l << ' ' << ans[k] << ' ' << m << endl;
				int v; cin >> v;
				if(v % 2){
					r = m;
				}else{
					l = m + 1;
				}
			}
			points.push_back({ans[k], l});
		}
		cout << "! " << points[0].first << ' ' << points[0].second << ' ' << points[1].first << ' ' << points[1].second << endl;
	}else{
		vector<pair<int, int>> points;
		for(int k = 0; k < 2; k++){
			int l = 1, r = n;
			while(l != r){
				int m = (l + r) >> 1;
				cout << "? " << l << ' ' << ans[k] << ' ' << m << ' ' << ans[k] << endl;
				int v; cin >> v;
				if(v % 2){
					r = m;
				}else{
					l = m + 1;
				}
			}
			points.push_back({l, ans[k]});
		}
		cout << "! " << points[0].first << ' ' << points[0].second << ' ' << points[1].first << ' ' << points[1].second << endl;
	}
}