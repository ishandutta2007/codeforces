//sobskdrbhvk
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

const int maxval = 1e6;
bool isprime[maxval + 1];
int sum[maxval + 1];
int a, b, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(isprime, true, sizeof isprime);
	isprime[0] = isprime[1] = false;
	for(int i = 2; i <= maxval; i++)
		if(isprime[i])
			for(int j = i * 2; j <= maxval; j += i)
				isprime[j] = false;
	for(int i = 1; i <= maxval; i++)
		sum[i] = sum[i - 1] + isprime[i];
	cin >> a >> b >> k;
	if(sum[b] - sum[a - 1] < k){
		cout << -1 << '\n';
		return 0;
	}
	int lo = 0, hi = b - a + 1;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		bool is = true;
		for(int i = a; i + mid - 1 <= b; i++)
			if(sum[i + mid - 1] - sum[i - 1] < k)
				is = false;
		if(is)
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << endl;
	return 0;
}