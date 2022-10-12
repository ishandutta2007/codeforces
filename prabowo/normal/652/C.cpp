#include <bits/stdc++.h>
using namespace std;

const int N = 300000;

int n, m;
int p[N];
pair <int, int> foe[N];
int a[N];
int suffixMin[N + 1];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i=0; i<n; i++)
		scanf ("%d", p + i),
		a[--p[i]] = i;
		
	for (int i=0; i<m; i++) {
		scanf ("%d %d", &foe[i].first, &foe[i].second);
		foe[i].first = a[--foe[i].first], foe[i].second = a[--foe[i].second];
		if (foe[i].second < foe[i].first) swap(foe[i].first, foe[i].second);		
	}
		
	sort (foe, foe + m);
		
	suffixMin[m] = n;
	for (int i=m-1; i>=0; i--) suffixMin[i] = min(foe[i].second, suffixMin[i + 1]);	
	
	int idx = 0;
	long long ans = 0;
	for (int i=0; i<n; i++) {
		while (idx < m && foe[idx].first < i) idx++;
		ans += suffixMin[idx] - i;
	}
	
	printf ("%I64d\n", ans);
	return 0;
}