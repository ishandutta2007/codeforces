#include <bits/stdc++.h>

using namespace std;

int A[101];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	vector<int> v1, v2;
	v1.push_back(0);
	for(int i = 0; i < n; i++){
		for(auto j : v1){
			v2.push_back(j + A[i]);
			v2.push_back(j - A[i]);
		}
		sort(v2.begin(), v2.end());
		v2.resize(unique(v2.begin(), v2.end()) - v2.begin());
		swap(v1, v2);
		v2.clear();
	}
	bool can_zero = true;
	for(auto i : v1) if(i == 0) can_zero = false;
	if(can_zero){
		cout << 0 << endl;
		return 0;
	}
	cout << 1 << endl;
	for(int iter = 0; iter < 20; iter++){
		for(int i = 0; i < n; i++){
			if(A[i] % 2){
				cout << i + 1 << endl;
				return 0;
			}
		}
		for(int i = 0; i < n; i++){
			A[i] /= 2;
		}
	}
}