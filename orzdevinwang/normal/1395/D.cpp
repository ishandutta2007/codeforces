#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, d, a[100011], cnta;
ll ans, qzh[100011];
int main() {
	scanf("%d%d%d", &n, &d, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) if(a[i] <= m) cnta = i;
	if(cnta != n) --n;
	for(int i = 1; i <= n; i++) qzh[i] = qzh[i - 1] + a[i];
//	cout << cnta << endl;
	for(int i = 0; i <= min(n / (d + 1), n - cnta); i++) {
		int g = n - (d + 1) * i;
//		cout << g << endl; 
		ans = max(ans, qzh[n] - qzh[n - i] + qzh[cnta] - qzh[max(cnta - g, 0)]);
//		cout << qzh[cnta] - qzh[max(cnta - g, 0)] << endl;
	}
	printf("%lld\n", ans + a[n + 1]);
	return 0;
}