#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, a[100000], twf=0, fif=0;
bool ok=1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int i=0; i<n; ++i) {
		if (a[i]==25) twf++;
		else if (a[i]==50&&twf) {
			fif++; twf--;
		}
		else if (a[i]==50) {
			ok=0; break;
		}
		else {
			if (fif&&twf) {
				fif--; twf--;
			}
			else if (twf>=3)
				twf-=3;
			else {
				ok=0; break;
			}
		}
	}
	cout <<(ok?"YES":"NO");
	return 0;
}