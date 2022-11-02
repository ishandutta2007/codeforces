#include <iostream>
#include <algorithm>
using namespace std;

int A[100000];
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n;
		cin >> n;
		for(int j=0;j<n;j++){
			cin >> A[j];
		}
		sort(A, A+n);
		int ans = min(A[n - 2] - 1, n - 2);
		cout << ans << endl;
	}
	return 0;
}