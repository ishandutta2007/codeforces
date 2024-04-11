#include <bits/stdc++.h>
#define m 1000000007
typedef long long ll;
using namespace std;

int A[300][300];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 2){
		for(int j = 0; j < n; j++){
			A[i][j] = i * n + j + 1;
		}
	}
	for(int i = 1; i < n; i += 2){
		for(int j = 0; j < n; j++){
			A[i][j] = i * n - j + 1 + n - 1;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << A[j][i] << ' ';
		}
		cout << endl;
	}
}