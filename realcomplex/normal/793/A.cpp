#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long change;
	cin >> change;
	bool can = true;
	long long need = 0;
	long long skaitli[n];
	for(int i = 0;i<n;i++){
		cin >> skaitli[i];
	}
	sort(skaitli,skaitli + n);
	for(int i = 1;i<n;i++){
		if((skaitli[i] - skaitli[0]) % change == 0){
			need += (skaitli[i] - skaitli[0]) / change;
		}
		else{
			can = false;
			break;
		}
	}
	if(can == true){
		cout << need;
	}
	else{
		cout << -1;
	}
	return 0;
}