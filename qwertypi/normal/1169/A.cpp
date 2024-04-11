#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n, a1, a2, b1, b2;
	cin >> n >> a1 >> a2 >> b1 >> b2;
	a2--; b2--;
	int A[101], B[101];
	fill(A, A+101, 0);
	fill(B, B+101, 0);
	A[0] = a1 - 1;
	B[0] = b1 - 1;
	int pos_A = 0, pos_B = 0;
	while(A[pos_A] != a2){
		A[pos_A+1] = (A[pos_A] + 1) % n;
		pos_A++;
	}
	while(B[pos_B] != b2){
		B[pos_B+1] = (B[pos_B] + n - 1) % n;
		pos_B++;
	}
	bool End = false;
	for(int i=0;i<min(pos_A, pos_B)+1;i++){
		if(A[i] == B[i]){
			cout << "YES";
			End = true;
			break;
		}
	}
	if(!End){
		cout << "NO";
	}
	return 0;
}