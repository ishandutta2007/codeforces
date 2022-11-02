#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int A[500][500];
int ans[500];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> A[i][j];
		}
	}
	for(int i=0;i<n;i++){
		ans[i] = 0;
	}
	int prod = 0;
	for(int i=0;i<n;i++){
		prod ^= A[i][0];
	}
	bool End = false;
	if(prod == 0){
		for(int i=0;i<n;i++){
			int ori = A[i][0];
			for(int j=1;j<m;j++){
				if(A[i][j] != ori){
					End = true;
					ans[i] = j;
					cout << "TAK" << endl;
					for(int i=0;i<n;i++){
						cout << ans[i] + 1 << ' ';
					}
					break;
				}
			}
			if(End){
				break;
			}
		}
		if(!End){
			cout << "NIE";
		}
	}else{
		cout << "TAK" << endl;
		for(int i=0;i<n;i++){
			cout << ans[i] + 1 << ' ';
		}
	}
	return 0;
}