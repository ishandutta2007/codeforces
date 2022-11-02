#include <iostream>
typedef long long ll;
using namespace std;
int main(){
	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		ll a, b, c;
		cin >> a >> b >> c;
		cout << (a + b + c) / 2 << endl;
	}
}