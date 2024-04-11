#include <bits/stdc++.h>

using namespace std;

int A[101][101];

vector<pair<int, int>> odd, even;

void add(pair<int, int> p, int c){
	cout << c << ' ' << p.first + 1 << ' ' << p.second + 1 << endl;
}

int32_t main(){
	int n;
	cin >> n;
	
	int o = 0, e = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if((i + j) % 2 == 1){
				odd.push_back({i, j});
			}else{
				even.push_back({i, j});
			}
		}
	}
	for(int i = 0; i < n * n; i++){
		int c;
		cin >> c;
		if(c == 1){
			if(e < even.size()){
				add(even[e++], 2);
			}else{
				add(odd[o++], 3);
			}
		}else if(c == 2){
			if(o < odd.size()){
				add(odd[o++], 1);
			}else{
				add(even[e++], 3);
			}
		}else{
			if(e < even.size()){
				add(even[e++], 2);
			}else if(o < odd.size()){
				add(odd[o++], 1);
			}
		}
	}
}