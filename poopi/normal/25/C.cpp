						/* in the name of Allah */
#include <iostream>
using namespace std;

#define int64 long long
int n, k;
int64 mat[310][310];

int main(){
	cin >> n;
	int64 sum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> mat[i][j];
			sum += mat[i][j];
		}
	}
	cin >> k;
	int64 a, b, c;
	for(int l = 0; l < k; l++){
		cin >> a >> b >> c;
		a--, b--;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int64 tmp = min(mat[i][a] + mat[b][j], mat[i][b] + mat[a][j]) + c;
				if(mat[i][j] > tmp){
					sum -= mat[i][j] - tmp;
					mat[i][j] = tmp;
				}
			}
		}
		cout << sum / 2;
		if(l < k - 1)
			cout << ' ';
		else cout << endl;
	}
	return 0;
}