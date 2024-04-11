#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	
	int sk = 0;
	while(a > 0 && b > 0){
		if(a > b){
			a-=2;
			b++;
		}
		else{
			b-=2;
			a++;
		}
		if(a >= 0 && b >= 0){
			sk++;
		}
	}
	cout << sk;
	return 0;
}