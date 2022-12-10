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

const int maxn = 2e5 + 85 - 69;
int a[maxn],
	b[maxn],
	c[maxn],
	ss[maxn],
	t, k, n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t >> k;
	for(int i = 0; i < t; i++)
		cin >> a[i];
	int sum = 0;
	for(int i = t - 2; i >= 0; i--){
		c[i] = max(0, a[i] - a[i + 1]);
		sum += c[i];
		b[i] = min(a[i], a[i + 1]);
	}
	b[t - 1] = a[t - 1];
	ss[0] = 2;
	for(int i = 0; i < t; i++)
		ss[i + 1] = ss[i] + a[i];
	sum += b[t - 1];
	if(sum > k){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < t - 1; i++){
		for(int j = b[i] - 1; j > 0 and sum < k; j--){
			b[i]--;
			c[i]++;
			sum++;
		}
	}
	if(sum < k){
		cout << -1 << endl;
		return 0;
	}
	cout << n << '\n';
	for(int j = 0; j < b[0] + c[0]; j++)
		cout << 1 << ' ' << ss[0] + j << '\n';
	for(int i = 0; i + 1 < t; i++){
		for(int j = 0; j < b[i]; j++)
			cout << ss[i] + j << ' ' << ss[i + 1] + j << '\n';
		for(int j = b[i]; j < a[i + 1]; j++)
			cout << ss[i] << ' ' << ss[i + 1] + j << '\n';
	}
	return 0;
}