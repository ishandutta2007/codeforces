#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int v;
	cin >> v;
	int a[10], Min = 1e9;
	for(int i = 1; i < 10; i++){
		cin >> a[i];
		Min = min(Min, a[i]);
	}
	int d = v / Min;
	v -= d * Min;
	if(d == 0){
		cout << -1 << endl;
		return 0;
	}
	while(d){
		for(int i = 9; i > 0; i--){
			if(v + Min >= a[i]){
				cout << i;
				v -= a[i] - Min;
				break;
			}
		}
		d--;
	}
	cout << endl;
	return 0;
}