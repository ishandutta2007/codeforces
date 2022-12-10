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
LL a[maxn],
   b[maxn],
   c[maxn],
   cnt[50],
   n, sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i], sum += b[i];
	if(sum % (n + n)){
		cout << -1 << endl;
		return 0;
	}
	sum /= n + n;
	for(int i = 0; i < n; i++){
		c[i] = a[i] + b[i] - sum;
		c[i] /= n;
		for(int j = 0; j < 40; j++)
			cnt[j] += (c[i] >> j) & 1LL;
	}
	for(int i = 0; i < n; i++){
		LL valor = 0,
		   valand = 0;
		for(int j = 0; j < 40; j++){
			if((c[i]>>j)&1LL){
				valand += cnt[j] * (1LL << j);
				valor += n * (1LL << j);
			}
			else
				valor += cnt[j] * (1LL << j);
		}
		if(valor != b[i] or valand != a[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 0; i < n; i++)
		cout << c[i] << ' ';
	cout << '\n';
	return 0;
}