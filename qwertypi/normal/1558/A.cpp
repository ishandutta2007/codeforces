#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

set<int> S;
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		S.clear();
		int u = a, v = b;
		int l = 0, r = 0;
		for(int i = 0; i < a + b; i++){
			if(i % 2){
				if(u){
					u--;
				}else{
					v--; l++;
				}
			}else{
				if(v){
					v--;
				}else{
					u--; l++;
				}
			}
		}
		u = a, v = b;
		for(int i = 0; i < a + b; i++){
			if(i % 2){
				if(v){
					v--; r++;
				}else{
					u--;
				}
			}else{
				if(u){
					u--; r++;
				}else{
					v--;
				}
			}
		}
		for(int i = l; i <= r; i += 2){
			S.insert(i);
		}
		swap(a, b);
		u = a, v = b, l = 0, r = 0;
		for(int i = 0; i < a + b; i++){
			if(i % 2){
				if(u){
					u--;
				}else{
					v--; l++;
				}
			}else{
				if(v){
					v--;
				}else{
					u--; l++;
				}
			}
		}
		u = a, v = b;
		for(int i = 0; i < a + b; i++){
			if(i % 2){
				if(v){
					v--; r++;
				}else{
					u--;
				}
			}else{
				if(u){
					u--; r++;
				}else{
					v--;
				}
			}
		}
		for(int i = l; i <= r; i += 2){
			S.insert(i);
		}
		cout << S.size() << endl;
		for(auto i : S){
			cout << i << ' ';
		} 
		cout << endl;
	}
}