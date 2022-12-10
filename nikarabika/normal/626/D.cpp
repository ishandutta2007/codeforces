//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 2000 + 85 - 69, maxval = 5000 + 1;
int a[maxn], n;
LD prob[maxval], prob2[maxval];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	LD makh = LD(1) * n * (n - 1) / 2.;
	sort(a, a + n);
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			prob[a[j] - a[i]] += LD(1) / makh;
	for(int i = 0; i < maxval; i++)
		for(int j = 0; j <= i; j++)
			prob2[i] += prob[j] * prob[i - j];
	for(int i = 1; i < maxval; i++)
		prob2[i] += prob2[i - 1];
	LD ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++){
			int val = a[j] - a[i];
			ans += prob2[val - 1] / makh;
		}
	cout.precision(10);
	cout << fixed << ans << endl;
	return 0;
}