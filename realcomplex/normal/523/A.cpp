#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	swap(n,m);
	char arr[n][m];
	for(int j = 0;j<n;j++)
		for(int i = 0;i<m;i++)
			cin >> arr[j][i];
	for(int i = 0;i<m;i++){
		for(int x = 0;x<2;x++){
			for(int j = 0;j<n;j++){
				cout << arr[j][i] << arr[j][i];
			}	
			cout << endl;
		}
	}
	return 0;
}