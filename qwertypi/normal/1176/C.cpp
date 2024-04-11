#include <iostream>

using namespace std;
const int seq[] = {4,8,15,16,23,42};
int A[500000];
int dp[7];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	dp[0] = n;
	for(int i=1;i<7;i++){
		dp[i] = 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<6;j++){
			if(seq[j] == A[i]){
				if(dp[j]){
					dp[j]--;
					dp[j+1]++;
				}
				break;
			}
		}
	}
	cout << n - 6 * dp[6];
}