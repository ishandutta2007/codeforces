#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 50 + 10;
LL fib[maxn];
LL n, k;
LL ans[maxn];

void make(int p, LL k){
	if(p == n)
		return;
	if(k < fib[n - p - 1]){
		ans[p] = p + 1;
		make(p + 1, k);
	}
	else{
		ans[p] = p + 2;
		ans[p + 1] = p + 1;
		make(p + 2, k - fib[n - p - 1]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	fib[0] = fib[1] = 1;
	for(int i = 2; i <= n; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	k--;
	make(0, k);
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}