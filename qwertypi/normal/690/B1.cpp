#include <bits/stdc++.h>
#define inf (1LL << 60)
#define int long long
using namespace std;

int A[52][52];
bool T[52][52];
int32_t main(){
	int n, m;
	cin >> n;
	m = n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			A[i][j] = s[j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(A[i][j] == '4'){
				T[i][j] = true;
			}
		}
	}
	int x1 = inf, x2 = -inf, y1 = inf, y2 = -inf;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(T[i][j]){
				x1 = min(i, x1); x2 = max(i, x2);
				y1 = min(j, y1); y2 = max(j, y2);
			}
		}
	}
	
	// cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	if(x1 == inf || x1 <= 0 || y1 == inf || y1 <= 0 || x2 == -inf || x2 >= n - 1 || y2 == -inf || y2 >= n - 1){
		cout << "No" << endl;
		return 0;
	}
	
	for(int i = x1; i <= x2; i++){
		for(int j = y1; j <= y2; j++){
			if(!T[i][j]){
				cout << "No" << endl;
				return 0;
			}
		} 
	}
	for(int i = x1; i <= x2; i++){
		if(A[i][y1 - 1] != '2'){
			cout << "No" << endl;
			return 0;
		}
		if(A[i][y2 + 1] != '2'){
			cout << "No" << endl;
			return 0;
		}
	}
	for(int i = y1; i <= y2; i++){
		if(A[x1 - 1][i] != '2'){
			cout << "No" << endl;
			return 0;
		}
		if(A[x2 + 1][i] != '2'){
			cout << "No" << endl;
			return 0;
		}
	}
	if(A[x1 - 1][y1 - 1] != '1' || A[x1 - 1][y2 + 1] != '1' || A[x2 + 1][y1 - 1] != '1' || A[x2 + 1][y2 + 1] != '1'){
		cout << "No" << endl;
		return 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!(x1 - 1 <= i && i <= x2 + 1) || !(y1 - 1 <= j && j <= y2 + 1)){
				if(A[i][j] != '0'){
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}