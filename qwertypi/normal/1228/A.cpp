#include <bits/stdc++.h>
 
using namespace std;
bool f(int x){
	set<int> K;
	while(x){
		if(K.find(x % 10) != K.end()){
			return 0;
		}
		K.insert(x % 10);
		x /= 10;
	}
	return 1;
}
 
int main(){
	int l, r;
	cin >> l >> r;
	for(int i = l; i <= r; i++){
		if(f(i)){
			cout << i;
			return 0;
		}
	}
	cout << -1;
}