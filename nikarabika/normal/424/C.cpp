//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e6 + 85 - 69;
int sum[maxn],
	n;

int get(int l, int r){
	return sum[l] ^ sum[r];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i + 1 < maxn; i++)
		sum[i + 1] = sum[i] ^ i;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		ans ^= x;
	}
	for(int i = 1; i <= n; i++){
		int cnt = n / i;
		if(cnt & 1)
			ans ^= get(n % i + 1, i);
		else
			ans ^= get(0, n % i + 1);
	}
	cout << ans << endl;
	return 0;
}