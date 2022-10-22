#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, a[100000], hi=0, toCheck=-1;
bool pos=1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i) {
		if (a[i]>=hi)
			hi=a[i];
		else
			toCheck=i;
	}
	
	if (toCheck!=-1) {
		for (int i=0; i<toCheck; ++i) {
			if (a[i]>a[toCheck]) {
				swap(a[i], a[toCheck]);
				break;
			}
		}
	}
	for (int i=1; i<n; ++i) {
		if (a[i]<a[i-1]) {
			pos=0;
			break;
		}
	}
	cout << (pos?"YES":"NO");
	return 0;
}