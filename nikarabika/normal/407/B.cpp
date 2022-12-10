#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

const int maxn = 1e3 + 10;
ll p[maxn], s[maxn], n;
const ll D = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	s[1] = 1;
	for(int i = 2; i <= n; i++){
		ll f = i - p[i] + 1;
		f = (((f + s[i - 1] - s[p[i] - 1]) % D) + D) % D;
		s[i] = (s[i - 1] + f) % D;
	}
	cout << (s[n] + n) % D << endl;
	return 0;
}