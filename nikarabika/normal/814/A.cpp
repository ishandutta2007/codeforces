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

#define YES return cout << "Yes", 0;
#define NO return cout << "No", 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	if (m >= 2) YES;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < m; j++)
		cin >> b[j];
	for (int i = 0; i < n; i++)
		if (a[i] == 0)
			a[i] = b[0];
	for (int i = 0; i + 1 < n; i++)
		if (a[i] > a[i + 1])
			YES;
	NO;
	return 0;
}