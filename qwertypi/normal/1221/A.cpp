#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<ll> A(n);
		ll sum = 0;
		for(int i=0;i<n;i++){
			cin >> A[i];
			sum += A[i];
		}
		sort(A.begin(), A.end());
		int curPos = 0;
		while(curPos + 1 < A.size()){
			if(A[curPos] == 2048){
				cout << "YES" << endl;
				goto Next;
			}
			if(A[curPos] == A[curPos+1]){
				A[curPos] *= 2;
				A.erase(A.begin()+curPos+1);
				sort(A.begin(), A.end());
			}else{
				curPos++;
			}
		}
		if(A[curPos] == 2048){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
		Next:;
	}
}