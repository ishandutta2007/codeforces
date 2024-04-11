#include <bits/stdc++.h>

using namespace std;

int cnt_1 = 0;
int A[200001];
int32_t main(){
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		cnt_1 += A[i];
	}
	
	for(int i = 0; i < q; i++){
		int v1, v2;
		cin >> v1 >> v2;
		if(v1 == 1){
			v2--;
			A[v2] = !A[v2];
			cnt_1 += A[v2] - !A[v2];
		}else{
			if(v2 <= cnt_1){
				cout << 1 << endl;
			}else{
				cout << 0 << endl;
			}
		}
	}
}