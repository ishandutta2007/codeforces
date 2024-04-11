#include <iostream>

using namespace std;

int n, m;
int A[300000];
int B[300000];
bool OK(int x){
	for(int i=0;i<n;i++){
		A[i] = B[i];
	}
	A[0] = (A[0] + x >= m) ? 0 : A[0];
	for(int i=1;i<n;i++){
		if(A[i] > A[i-1]){
			if(A[i] + x - m >= A[i-1]){
				A[i] = A[i-1];
			}else{
				A[i] = A[i];
			}
		}else{
			if(A[i] + x >= A[i-1]){
				A[i] = A[i-1];
			}else{
				return false;
			}
		}
	}
	return true;
}

int bin_search(){
	int upper = m - 1;
	int lower = 0;
	while(upper != lower){
		int mid = (upper + lower) >> 1;
		if(OK(mid)){
			upper = mid;
		}else{
			lower = mid + 1;
		}
	}
	return lower;
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> B[i];
	}
	cout << bin_search() << endl;
}