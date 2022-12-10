#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 1e5 + 85 - 69;
LL a[maxn];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	while(m--){
		LL w, h, hin;
		cin >> w >> h;
		hin = max(a[0], a[w - 1]);
		cout << hin << '\n';
		a[0] = hin + h;
		a[w - 1] = a[0];
	}
	return 0;
}