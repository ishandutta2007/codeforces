#include "bits/stdc++.h"
using namespace std;
int a , b;
int main(){
	cin >> a >> b;
	long long ans = 1;
	for(int i = 1 ; i <= min(a , b) ; ++i){
		ans *= i;
	}
	cout << ans << endl;
}