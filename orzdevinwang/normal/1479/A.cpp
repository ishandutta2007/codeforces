#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, a[N];
int ask(int k) {
	if(k == 0 || k == n + 1) return 1e9;
	cout << "? " << k << "\n";
	fflush(stdout);
	int v; cin >> v;
	return v;
}
void Main() {
	cin >> n;
	int l = 1, r = n;
	while(l <= r) {
		int mid = (l + r) >> 1;
		int v1 = ask(mid - 1), v2 = ask(mid), v3 = ask(mid + 1);
		if(v1 > v2 && v2 < v3) return cout << "! " << mid << "\n", void();
		if(v1 < v2) r = mid - 1;
		else l = mid + 1;
	}
	assert(0);
} 
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}