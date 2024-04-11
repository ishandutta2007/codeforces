#include <iostream>
#include <algorithm>
using namespace std;
 
long long A[100000];
int main(){
	int64_t n, m, k;
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		cin >> A[i];
	}
	int64_t curBound = 0;
	int ans = 0;
	int pos = 0;
	while(pos < m){
		curBound += (long long)(A[pos] - 1 - curBound) / k * k;
		int cnt = 0;
		while(pos < m && A[pos] <= curBound + k){
			cnt++;
			pos++;
		}
		curBound += cnt;
		ans++;
	}
	cout << ans;
	return 0;
}