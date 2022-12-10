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

const int maxn = 1e6 + 85 - 69;
LL a[maxn];
int n;
LL k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i], a[i] = __gcd(a[i], k);
	LL an = 1;
	for(int i = 0; i < n; i++)
		an = an / __gcd(an, a[i]) * a[i];
	if(an == k)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}