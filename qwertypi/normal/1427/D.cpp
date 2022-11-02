#include <bits/stdc++.h>

using namespace std;

int A[53], B[53];
bool used[53];

vector<vector<int>> Q;

int n;

void apply(vector<int> input){
	vector<int> res;
	int cur = 0;
	vector<pair<int, int>> bound;
	for(auto i : input){
		bound.push_back({cur, cur + i});
		cur += i;
	}
	
	reverse(bound.begin(), bound.end());
	
	for(auto i : bound){
		for(int k = i.first; k < i.second; k++){
			res.push_back(A[k]);
		}
	}
	
	for(int i = 0; i < n; i++){
		A[i] = res[i];
	}
}

void print(){
	for(int i = 0; i < n; i++){
		cout << A[i] << ' ';
	}
	cout << endl;
}

void update(){
	for(int i = 0; i < n; i++){
		B[A[i]] = i;
	}
}

int32_t main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	update();
	
	for(int i = 1; i <= n; i++){
		vector<int> query;
		fill(used, used + n + 1, 0);
		for(int j = 1; j < i; j++){
			used[B[j]] = true;
		}
		
		int cnt = 0;
		
		if((n - i) % 2 == 0){
			for(int j = 0; j < n; j++){		
				if(used[j]){
					if(cnt != 0){
						query.push_back(cnt);
					}
					query.push_back(1);
					cnt = 0;
				}else if(A[j] == i){
					if(cnt != 0){
						query.push_back(cnt);
					}
					cnt = 1;
				}else{
					cnt++;
				}
			}
			if(cnt != 0){
				query.push_back(cnt);
			}
		}else{
			for(int j = 0; j < n; j++){
				if(used[j]){
					if(cnt != 0){
						query.push_back(cnt);
					}
					query.push_back(1);
					cnt = 0;
				}else if(A[j] == i){
					query.push_back(cnt + 1);
					cnt = 0;
				}else{
					cnt++;
				}
			}
			if(cnt != 0){
				query.push_back(cnt);
			}
		}
		
		apply(query);
//		cout << "A[i]: ";
//		for(int i = 0; i < n; i++){
//			cout << A[i] << ' ';
//		}
//		cout << endl;
		if(query.size() == 1) continue;
		Q.push_back(query);
		update();
	}
	
	cout << Q.size() << endl;
	for(auto i : Q){
		cout << i.size() << ' ';
		for(auto j : i){
			cout << j << ' ';
		}
		cout << endl;
	}
}