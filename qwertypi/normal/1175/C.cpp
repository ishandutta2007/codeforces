#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


int A[200000];
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n, k;
		cin >> n >> k;
		for(int j=0;j<n;j++){
			cin >> A[j];
		}
		sort(A, A+n);
		int min_dis = (1 << 30) - 1;
		int ans = -1;
		for(int j=0;j<n-k;j++){
			if(A[j+k] - A[j] < min_dis){
				ans = (A[j+k] + A[j]) / 2;
				min_dis = A[j+k] - A[j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}