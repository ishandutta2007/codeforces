#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define smin(x, y) (x) = min((x), (y))

const int maxn = 2e5 + 85 - 69;
LL a[maxn], b[maxn], s[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	n--;
	for(int i = 0; i < n; i++){
		b[i] = a[i + 1] - a[i];
		s[i + 1] = s[i] + b[i];
	}
	LL ret = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
	int len;
	if(n & 1)
		len = n / 2 + 1;
	else
		len = n / 2;
	for(int i = 0; i + len - 1 < n; i++)
		smin(ret, s[i + len] - s[i]);
	cout << ret << endl;
	return 0;
}