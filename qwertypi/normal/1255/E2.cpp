#include <bits/stdc++.h>
#pragma optimize("Ofast")
typedef long long ll;
using namespace std;
int A[1000000];
bool isPrime[1000001];

int n;

ll f(ll i){
	ll res = 0;
	ll curInt = A[0];
	ll dx;
	ll g = A[0] % i;
	if(g >= i - g){
		dx = -(i - g);
	}else{
		dx = g;
	}
	for(int j = 1; j < n; j++){
		res += abs(dx);
		curInt = A[j] + dx;
		g = curInt % i;
		if(g >= i - g){
			dx = -(i - g);
		}else{
			dx = g;
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fill(isPrime + 2, isPrime + 1000001, 1);
	for(int i = 2; i <= 1000000; i++){
		if(isPrime[i]){
			for(int j = i * 2; j <= 1000000; j += i){
				isPrime[j] = 0;
			}
		}
	}
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
	ll cnt = sum;
	for(int i = 2; i <= 1000000; i++){
		if(isPrime[i] && cnt % i == 0){
			while(cnt % i == 0){
				cnt /= i;
			}
			ans = min(ans, f(i));
		}
	}
	if(cnt != 1){
		ans = min(ans, f(cnt));
	}
	cout << ans;
}