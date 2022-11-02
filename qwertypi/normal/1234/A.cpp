#include <bits/stdc++.h>

using namespace std;
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int sum = 0;
		for(int i = 0; i < n; i++){
			int v;
			cin >> v;
			sum += v;
		}
		cout << (sum + n - 1) / n << endl;
	}
}