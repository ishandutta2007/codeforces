#include <iostream>
#include <algorithm>
using namespace std;
int ans[1000];
bool inOrder[999];
int A[1000][3];
int main(){
	int n, k;
	cin >> n >> k;
	fill(inOrder, inOrder + n - 1, 0);
	for(int i=0;i<k;i++){
		for(int j=0;j<3;j++){
			cin >> A[i][j];
		}
		A[i][1]--;
		A[i][2]--;
		if(A[i][0] == 1){
			for(int j = A[i][1]; j < A[i][2]; j++){
				inOrder[j] = 1;
			}
		}
	}
	for(int i=0;i<k;i++){
		if(A[i][0] == 0){
			if(all_of(inOrder + A[i][1], inOrder + A[i][2], [](bool n){return n;})){
				cout << "NO";
				return 0;
			}
		}
	}
	ans[0] = 1000;
	for(int i=0;i<n-1;i++){
		ans[i+1] = ans[i] + (inOrder[i] ? 1000 : -1);
	}
	cout << "YES" << endl;
	for(int i=0;i<n;i++){
		cout << ans[i] << ' ';
	}
}