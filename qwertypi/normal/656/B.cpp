#include <iostream>
#include <vector>
using namespace std;

int A[16];
int B[16];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	for(int i=0;i<n;i++){
		cin >> B[i];
	}
	int ans = 0;
	for(int i=0;i<720720;i++){
		for(int j=0;j<n;j++){
			if(i % A[j] == B[j]){
				ans++;
				break;
			}
		}
	}
	cout << (long double)ans / (720720);
}