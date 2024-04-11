#include <iostream>

using namespace std;
int prec[200001][26];
int cmp(int A[26], int B[26]){
	for(int i=0;i<26;i++){
		if(A[i] < B[i]){
			return false;
		}
	}
	return true;
}


int main(){
	int n;
	string s;
	cin >> n >> s;
	for(int i=0;i<26;i++){
		prec[0][i] = 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			prec[i][j] = prec[i-1][j];
		}
		prec[i][s[i-1] - 'a']++;
	}
	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		string s1;
		cin >> s1;
		int B[26];
		for(int j=0;j<26;j++){
			B[j] = 0;
		}
		for(auto j:s1){
			B[j - 'a']++;
		}
		int upper = n;
		int lower = 0;
		while(upper != lower){
			int mid = (upper + lower) / 2;
			if(cmp(prec[mid], B)){
				upper = mid;
			}else{
				lower = mid + 1;
			}
		}
		cout << lower << endl;
	}
}