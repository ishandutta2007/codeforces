#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO;
	int n;
	cin >> n;
	int a[n];
	for(int i = 0 ; i < n; i ++ )
		cin >> a[i];
	sort(a, a + n);
	cout << min(a[n - 2] - a[0], a[n - 1] - a[1]);
	return 0;
}