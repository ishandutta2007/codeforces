#include <iostream>
#include <numeric>
using namespace std;
int main(){
    int A[4];
    for(int i=0;i<4;i++){
        cin >> A[i];
    }
    if(accumulate(A, A+4, 0LL) % 2 == 1){
        cout << "NO";
        return 0;
    }
    int mid = accumulate(A, A+4, 0LL) / 2;
    for(int i=0;i<(1<<4);i++){
    	int mask = i;
    	int cnt = 0;
        for(int j = 0; j < 4; j++){
        	if(mask % 2){
        		cnt += A[j];
			}
			mask /= 2;
		}
		if(cnt == mid){
			cout << "YES";
			return 0;
		}
    }
    cout << "NO";
}