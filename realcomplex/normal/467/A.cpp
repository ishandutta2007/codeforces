#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	int c,h;
	int sk = 0;
	for(int i = 0;i<n;i++){
		cin >> c >> h;
		if(c <= h - 2){
			sk++;
		}
	}
	cout << sk;
	return 0;
}