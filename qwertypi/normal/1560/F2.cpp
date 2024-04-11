#include <bits/stdc++.h>

using namespace std;

int A[10];
int ans[10];
void solve(){
	int n, k;
	cin >> n >> k;
	int x = n, d = 0;
	while(x > 0) A[d] = x % 10, x /= 10, d++;
	reverse(A, A + d);
	set<int> used;
	int _min = 10, _max = -1;
	bool eq = true;
	for(int i = 0; i < d; i++){
		// cout << i << ' ' << k << ' ' << eq << endl;
		if(!eq){
			if(used.find(0) != used.end()){
				ans[i] = 0;
			}else if(k > 0){
				used.insert(0); k--;
				ans[i] = 0;
				_min = min(_min, 0);
				_max = max(_max, 0);
			}else{
				ans[i] = *used.begin();
			}
		}else if(k >= 2 || k >= 1 && used.find(A[i]) != used.end()){
			ans[i] = A[i];
			if(used.find(A[i]) == used.end()){
				used.insert(A[i]); k--;
				_min = min(_min, A[i]);
				_max = max(_max, A[i]);
			}
		}else if(k == 0){
			ans[i] = *used.lower_bound(A[i]);
			bool fail = false, success = false;
			for(int j = i + 1; j < d; j++){
				if(A[j] > _max){
					fail = true;
					break;
				}else if(A[j] < _max){
					success = true;
					break;
				}
			}
			if(fail){
				ans[i] = *used.upper_bound(A[i]);
			}
		}else{
			bool fail = false, success = false;
			for(int j = i + 1; j < d; j++){
				if(A[j] > max(A[i], _max)){
					fail = true;
					break;
				}else if(A[j] < max(A[i], _max)){
					success = true;
					break;
				}
			}
			if(!fail && !success) success = true;
			if(success){
				used.insert(A[i]); k--;
				ans[i] = A[i];
				_min = min(_min, A[i]);
				_max = max(_max, A[i]);
			}else{
				assert(A[i] != 9);
				ans[i] = A[i] + 1;
				if(used.find(A[i] + 1) == used.end()){
					used.insert(A[i] + 1); k--;
					_min = min(_min, A[i] + 1);
					_max = max(_max, A[i] + 1);
				}
			}
		}
		
		if(ans[i] > A[i]) eq = false;
	}
	
	string rans;
	for(int i = 0; i < d; i++){
		rans.push_back('0' + ans[i]);
	}
	cout << rans << endl;
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}