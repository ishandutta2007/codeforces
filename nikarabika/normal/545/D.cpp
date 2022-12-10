#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 1e5 + 10;
LL t[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> t[i];
	sort(t, t + n);
	LL time = 0, ans = 0;
	for(int i = 0; i < n; i++){
		if(time > t[i])
			continue;
		ans++;
		time += t[i];
	}
	cout << ans << endl;
	return 0;
}