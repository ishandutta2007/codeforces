#include <iostream>

#define MX_N 100010

using namespace std;

int arr[MX_N][3];
int n,m,s,f;

int main() {
	int i,j;
	cin >> n >> m >> s >> f;
	for(i=0;i<m;i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	for(i=0,j=1;s != f;j++) {
		if(arr[i][0] == j) {
			
			if(s < f && arr[i][1]-1 <= s && s <= arr[i][2]) {
				cout << "X";
				i++;
				continue;
			}else if(s > f && arr[i][1] <= s && s <= arr[i][2] + 1) {
				cout << "X";
				i++;
				continue;
			}
			
			i++;
		}
		if(s < f) {
			cout << "R";
			s++;
		}else {
			cout << "L";
			s--;
		}	
	}
	cout << endl;
	return 0;
}