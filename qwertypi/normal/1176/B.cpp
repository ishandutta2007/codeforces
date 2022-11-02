#include <iostream>

using namespace std;
int A[3];
int main(){
	int t;
	cin >> t;
	for(int Case = 0; Case < t; Case++){
		for(int i=0;i<3;i++){
			A[i]= 0;
		}
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
			int k;
			cin >> k;
			k %= 3;
			A[k]++;
		}
		int ans = 0;
		ans += A[0];
		ans += min(A[1],A[2]);
		int h = min(A[1],A[2]);
		A[1] -= h;
		A[2] -= h;
		ans += A[1] / 3 + A[2] / 3;
		cout << ans << endl;
	}
}