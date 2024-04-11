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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n], b[n];
	int x = 1;
	for(int i = 0; i < n; i++)
		cin >> a[i], x = x / __gcd(x, a[i]) * a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	int cnt = 0;
	for(int i = 0; i < x; i++)
		for(int j = 0; j < n; j++)
			if(i % a[j] == b[j]){
				cnt++;
				break;
			}
	cout.precision(10);
	cout << fixed << LD(cnt) / x << endl;
	return 0;
}