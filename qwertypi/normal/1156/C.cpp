#include <iostream>
#include <algorithm>
using namespace std;

int A[200000];
bool used[200010];
int main(){
	fill(used, used+200010, 0);
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	sort(A, A+n);
	int L = 0, R =  n / 2;
	int ans = 0;
	while(R < n){
		if(A[R] - A[L] >= k){
			used[L] = used[R] = 1;
			R++;
			L++;
			ans++;
		}else{
			R++;
		}
		while(used[L]){
			L++;
			R = max(R, L+1);
		}
	}
	cout << ans;
}