#include <iostream>
#include <algorithm>
#include <set>
#include <numeric> 
using namespace std;

int A[100];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	sort(A, A+n);
	int half = accumulate(A, A+n, 0) / 2;
	int ans = 0;
	for(int i=n-1;i>=0;i--){
		half -= A[i];
		ans++;
		if(half < 0){
			cout << ans;
			return 0;
		}
	}
	return 0;
}