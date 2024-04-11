#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int A[1000000];
bool isPrime[1000001];
int main(){
	fill(isPrime + 2, isPrime + 1000001, 1);
	for(int i = 2; i <= 1000000; i++){
		if(isPrime[i]){
			for(int j = i * 2; j <= 1000000; j += i){
				isPrime[j] = 0;
			}
		}
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	ll sum = accumulate(A, A + n, 0LL); 
	if(sum == 1){
		cout << -1 << endl;
		return 0;
	}
	ll ans = (1LL << 60); 
	for(int i = 2; i <= 1000000; i++){
		if(isPrime[i] && sum % i == 0){
			ll res = 0;
			int curInt = A[0];
			int dx;
			if(A[0] % i >= i - A[0] % i){
				dx = -(i - A[0] % i);
			}else{
				dx = A[0] % i;
			}
			for(int j = 1; j < n; j++){
				res += abs(dx);
				curInt = A[j] + dx;
				if(curInt % i >= i - curInt % i){
					dx = -(i - curInt % i);
				}else{
					dx = curInt % i;
				}
			}
			ans = min(ans, res);
		}
	}
	cout << ans;
}