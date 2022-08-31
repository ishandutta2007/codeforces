#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 2e5 + 7;
int n, a, b, k;
char s[N];
int r[N], tp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> a >> b >> k;
	cin >> (s + 1);
	int now = 0;
	L(i, 1, n) {
		if(s[i] == '0') ++now;
		if(s[i] == '1' && now) r[++tp] = now, now = 0;
	}
	if(now) r[++tp] = now;
	int sum = 0;
	L(i, 1, tp) sum += r[i] / b;
	
	cout << sum - a + 1 << "\n";
	now = 0;
	L(i, 1, n) {
		if(s[i] == '0') {
			++ now;
			if(now % b == 0 && sum >= a) cout << i << " ", sum --;	
		}
		if(s[i] == '1' && now) now = 0;
	}
	cout << "\n";
	return 0;
}