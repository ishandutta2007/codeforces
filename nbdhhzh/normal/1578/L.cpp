#include<bits/stdc++.h> 
using namespace std;
int n, l, r;
double p;
double check(int x) {
	double ans = 0;
	if (x + 3 <= n)
		ans += 1. * (n - x) * (n - x - 1) * (n - x - 2) / n / (n - 1) / (n - 2);
	if (x + 2 <= n)
		ans += 3. * (n - x) * (n - x - 1) * x / n / (n - 1) / (n - 2) / 2;
	return 1 - ans;
}
int main() {
	scanf("%d%lf", &n, &p);
	for(l = 0, r = n - 1; l < r;) {
		int mid = l + r >> 1;
		if(check(mid) >= p)r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}