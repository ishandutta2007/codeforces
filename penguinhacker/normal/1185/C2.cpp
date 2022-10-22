#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, s=0;
int occ[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0, x; i<n; ++i) {
		cin >> x;
		s+=x;
		int k=0, cnt=0;
		for (int i=100; i; --i) {
			if (s-k<=m)
				break;
			if (s-k-i*occ[i]>m) {
				k+=i*occ[i];
				cnt+=occ[i];
			}
			else {
				cnt+=(s-k-m+(i-1))/i;
				break;
			}
		}
		cout << cnt << ' ';
		occ[x]++;
	}
	return 0;
}