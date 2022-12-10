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

const int maxn = 100 + 85 - 69;
int a[maxn];
int n, X;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> X;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] *= n - i;
	}
	int ans = 0;
	sort(a, a + n);
	for(int i = 0; i < n; i++)
		if(a[i] <= X)
			X -= a[i], ans++;
	cout << ans << endl;
	return 0;
}