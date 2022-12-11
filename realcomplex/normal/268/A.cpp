#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int c[n][2];
	for(int i = 0;i<n;i++){
		cin >> c[i][0] >> c[i][1];
	}
	int sk = 0;
	for(int i = 0;i<n;i++){
		for(int x = 0;x<n;x++){
			if(c[i][0] == c[x][1]){
				sk++;
			}
		}
	}
	cout << sk;
	return 0;
}