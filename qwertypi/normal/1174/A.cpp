#include <iostream>
#include <numeric>
using namespace std;
int A[2000];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<2*n;i++){
        cin >> A[i];
    }
    int sum_A = accumulate(A, A+n, 0);
    int sum_B = accumulate(A+n, A+2*n, 0);
    if(sum_A != sum_B){
        for(int i=0;i<2*n;i++){
            cout << A[i] << ' ';
        }
        exit(0);
    }
    int v = A[0];
    for(int i=n;i<2*n;i++){
        if(v != A[i]){
            swap(A[0], A[i]);
            for(int i=0;i<2*n;i++){
                cout << A[i] << ' ';
            }
            exit(0);
        }
    }
    for(int i=1;i<n;i++){
    	if(v != A[i]){
    		swap(A[i], A[n]);
            for(int i=0;i<2*n;i++){
                cout << A[i] << ' ';
            }
            exit(0);
		}
	}
	cout << -1;
	return 0;
}