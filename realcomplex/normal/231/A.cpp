#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	//int task[n];
	int sk = 0;
	char a,b,c;
	for(int i = 0;i<n;i++){
		cin >> a >> b >> c;
		if((a == '1' && b == '1') ||(b == '1' && c == '1')|| (a == '1' && c == '1')  ){
			sk++;
		}
	}
	cout << sk;
	
	return 0;
}