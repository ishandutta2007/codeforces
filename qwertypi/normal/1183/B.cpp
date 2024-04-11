#include <iostream>
#include <algorithm> 
using namespace std;
int main(){
	int q;
	cin >> q;
	int A[100];
	for(int i=0;i<q;i++){
		int n, k;
		cin >> n >> k;
		for(int j=0;j<n;j++){
			cin >> A[j];
		}
		if(*max_element(A, A+n) - *min_element(A, A+n) > 2 * k){
			cout << -1 << endl;
		}else{
			cout << *min_element(A, A+n) + k << endl;
		}
	}
	return 0;
}