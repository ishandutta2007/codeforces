#include <bits/stdc++.h>

using namespace std;

int main() {
	
	char cip;
	int xc,yc;
	for(int i = 1;i<=5;i++){
		for(int x = 1;x<=5;x++){
			cin >> cip;
			if(cip == '1'){
				yc = i;
				xc = x;
			}
		}
	}
	cout << (max(3,yc) - min(3,yc)) + (max(3,xc) - min(3,xc));
	return 0;
}