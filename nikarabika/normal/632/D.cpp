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

const int maxval = 1000 * 1000 + 85 - 69;
int a[maxval],
	cnt[maxval],
	n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] <= m)
			cnt[a[i]]++;
	}
	for(int i = m; i > 0; i--)
		for(int j = i + i; j <= m; j += i)
			cnt[j] += cnt[i];
	int maxid = 1;
	for(int i = m; i >= 1; i--)
		if(cnt[i] >= cnt[maxid])
			maxid = i;
	cout << maxid << ' ' << cnt[maxid] << '\n';
	for(int i = 0; i < n; i++)
		if(maxid % a[i] == 0)
			cout << i + 1 << ' ';
	cout << '\n';
	return 0;
}