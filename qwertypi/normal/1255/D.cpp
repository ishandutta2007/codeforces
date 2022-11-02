#include <bits/stdc++.h>

using namespace std;
char A[100][100];
char ans[100][100];
char ind(int k){
	if(k < 10){
		return '0' + k;
	}else if(k < 36){
		return 'a' + k - 10;
	}else{
		return 'A' + k - 36;
	}
}

void sub(){
	int r, c, k;
	cin >> r >> c >> k;
	for(int i = 0; i < r; i++){
		cin >> A[i];
	}
	int cnt = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cnt += A[i][j] == 'R';
		}
	}
	
	int curInd = 0;
	int curCnt = 0;
	for(int i = 0; i < r; i++){
		if(i % 2){
			for(int j = c - 1; j >= 0; j--){
				if(A[i][j] == 'R'){
					curCnt++;
				}
				if(curCnt > cnt / k + (curInd < cnt % k)){
					curCnt = 1;
					curInd++;
				}
				ans[i][j] = ind(curInd);
			}
		}else{
			for(int j = 0; j < c; j++){
				if(A[i][j] == 'R'){
					curCnt++;
				}
				if(curCnt > cnt / k + (curInd < cnt % k)){
					curCnt = 1;
					curInd++;
				}
				ans[i][j] = ind(curInd);
			}
		}
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << ans[i][j];
		}
		cout << endl;
	}
}

int32_t main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}