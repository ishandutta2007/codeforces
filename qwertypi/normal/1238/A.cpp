#include <iostream>
 
using namespace std;
 
void sub(){
	long long x, y;
	cin >> x >> y;
	if(x - y != 1){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
 
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}