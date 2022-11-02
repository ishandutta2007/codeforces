#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void sub(){
	int a, b;
	cin >> a >> b;
	if(a == 1){
		if(b == 1){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}else if(a <= 3){
		if(b <= 3){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}else{
		cout << "YES" << endl;
	}
}

int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}