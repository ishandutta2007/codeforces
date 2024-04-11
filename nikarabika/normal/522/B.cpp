#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 2e5 + 85 - 69;
LL h[maxn], w[maxn], lmax[maxn], rmax[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	LL wsum = 0;
	for(int i = 1; i <= n; i++){
		cin >> w[i] >> h[i];
		wsum += w[i];
		lmax[i] = max(lmax[i - 1], h[i - 1]);
	}
	for(int i = n; i >= 1; i--)
		rmax[i] = max(rmax[i + 1], h[i + 1]);
	for(int i = 1; i <= n; i++)
		cout << (wsum - w[i]) * max(lmax[i], rmax[i]) << ' ';
	cout << endl;
	return 0;
}