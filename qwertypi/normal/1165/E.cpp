#include <iostream>
#include <algorithm>
#define inf (1 << 30)
#define m 998244353
using namespace std;
typedef long long ll;
ll A[200000];
ll B[200000];

int cmp(int a, int b){
	return a > b;
}
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	for(int i=0;i<n;i++){
		cin >> B[i];
	}
	for(int i=0;i<n;i++){
		A[i] *= (ll)(n - i) * (i + 1);
	}
	sort(A, A+n);
	sort(B, B+n, cmp);
	int ans = 0;
	for(int i=0;i<n;i++){
		ans += ((A[i] % m) * B[i]) % m;
		ans %= m;
	}
	cout << ans;
	return 0;
}