#include "bits/stdc++.h"
using namespace std;
int a[3];
int main(){
	cin >> a[0] >> a[1] >> a[2];
	sort(a , a + 3);
	if(a[0] == 1){
		cout << "YES\n";
		return 0;
	}
	if(a[0] == 2 && a[1] == 2){
		cout << "YES\n";
		return 0;
	}
	if(a[0] == 2 && a[1] == 4 && a[2] == 4){
		cout << "YES\n";
		return 0;
	}
	if(a[0] == 3 && a[2] == 3){
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
}