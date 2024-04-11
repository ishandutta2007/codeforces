#include <bits/stdc++.h>

using namespace std;

int A[100000], total[100000];

vector<pair<int, int>> ans;

void answer(int a, int b){
	ans.push_back({a + 1, b + 1});
	total[b]++;
}

vector<pair<int, int>> v1, v2, v3;
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	int cnt = n - 1;
	for(int i = n - 1; i >= 0; i--){
		if(A[i] == 1){
			v1.push_back({i, cnt});
			answer(i, cnt--);
		}else if(A[i] == 2){
			if(v1.size() == 0 && v2.size() == 0){
				cout << -1 << endl;
				return 0;
			}
			pair<int, int> sos;
			if(v1.size()){
				sos = v1.back();
				v1.pop_back();
			}else{
				sos = v2.back();
				v2.pop_back();
			}
			sos.first = i;
			v3.push_back(sos);
			answer(i, sos.second);
		}else if(A[i] == 3){
			if(v1.size() == 0 && v3.size() == 0){
				cout << -1 << endl;
				return 0;
			}
			pair<int, int> sos;
			if(v3.size()){
				sos = v3.back();
				v3.pop_back();
			}else{
				sos = v1.back();
				v1.pop_back();
			}
			answer(i, cnt);
			answer(sos.first, cnt);
			v3.push_back({i, cnt});
			cnt--;
		}
	}
	
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i.second << ' ' << i.first << endl;
	}
}