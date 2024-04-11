#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	scanf("%d", &n);
	
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a, a+n);
	
	multiset<int> m;
	for (int i = n/2; i < n; i++) {
		m.insert(a[i]);
	}
	
	int ans = n/2;
	for (int i = 0; i < n/2; i++) {
		
		if (m.lower_bound(a[i]*2) == m.end()) break;
		m.erase(m.lower_bound(a[i]*2));
		
	}
	
	printf("%d", ans + m.size());
}