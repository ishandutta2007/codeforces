#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e6 + 7;
int n, m, x[N], p[N], pos[N];
int arr[N], atot;
ll ad[N], w[N], pre[N], suf[N];
void Main() {
	cin >> n >> m;
	atot = 0;
	L(i, 1, n) {
		cin >> x[i] >> p[i];
		arr[++atot] = x[i]; 
		arr[++atot] = x[i] - p[i];
		arr[++atot] = x[i] + p[i]; 
	}
	sort(arr + 1, arr + atot + 1);
	atot = unique(arr + 1, arr + atot + 1) - arr - 1;
	L(i, 0, atot + 1) ad[i] = w[i] = 0; 
	L(i, 1, n) {
		pos[i] = lower_bound(arr + 1, arr + atot + 1, x[i]) - arr;
		int l = lower_bound(arr + 1, arr + atot + 1, x[i] - p[i]) - arr;
		int r = lower_bound(arr + 1, arr + atot + 1, x[i] + p[i]) - arr;
		ad[l] += 1;
		ad[pos[i]] -= 2;
		ad[r] += 1;
	}
	L(i, 1, atot) ad[i] += ad[i - 1];
	L(i, 1, atot - 1) w[i + 1] = w[i] + ad[i] * (arr[i + 1] - arr[i]);
	L(i, 1, atot) w[i] = max(w[i] - m, 0LL);
	L(i, 1, atot) pre[i] = suf[i] = w[i] == 0 ? -1e18 : w[i];
	L(i, 1, atot - 1) pre[i + 1] = max(pre[i + 1], pre[i] + (arr[i + 1] - arr[i])); 
	R(i, atot, 2) suf[i - 1] = max(suf[i - 1], suf[i] + (arr[i] - arr[i - 1])); 
	L(i, 1, atot) w[i] = max(pre[i], suf[i]);
	L(i, 1, n) cout << (w[pos[i]] <= p[i]);
	cout << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);  
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}