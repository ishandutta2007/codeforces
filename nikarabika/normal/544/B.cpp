#include <bits/stdc++.h>

using namespace std;

int n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	if(k > (n * n + 1) / 2){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if((i + j) & 1)
				cout << "S";
			else if(k){
				cout << "L";
				k--;
			}
			else
				cout << "S";
		}
		cout << endl;
	}
	return 0;
}