#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn = 1e5 + 10;
int p[maxn], a[maxn];
int n, m, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p[a[i]] = i;
	}
	long long int ans = 0;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		ans += ll(p[x] + k - 1) / k;
		if(p[x] == 1)
			continue;
		int t = p[x];
		p[x]--;
		p[a[p[x]]]++;
		swap(a[t - 1], a[t]);
	}
	cout << ans << endl;
	return 0;
}