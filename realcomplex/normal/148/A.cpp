#include <iostream>
using namespace std;

int main() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int n;
	cin >> n;
	int sk = 0;
	for(int i = 1;i<=n;i++){
		if(i % a == 0 || i % b == 0 || i % c == 0 || i % d == 0){
			sk++;
		}
	}
	cout << sk;
	return 0;
}