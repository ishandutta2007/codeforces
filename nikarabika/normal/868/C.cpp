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

const int maxn = 1e5 + 10;
bool mark[maxn];
int a[maxn][10];
int n, k;
int num[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> a[i][j];
			num[i] += a[i][j] << j;
		}
		mark[num[i]] = true;
	}
	if (mark[0])
		return cout << "YES", 0;
	for (int i = 0; i < 16; i++)
		if (mark[i])
			for (int smask = 15 ^ i; smask; smask = (smask - 1) & (15 ^ i))
				if (mark[smask])
					return cout << "YES", 0;
	cout << "NO";
	return 0;
}