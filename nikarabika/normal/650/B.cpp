//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define left lef
#define right righ
#define int long long

const int maxn = 5e5 + 85 - 69;
LL left[maxn],
   right[maxn];
string s;
int ans, n;
LL a, b, T;

int leftans(LL pool, int idx){
	int lo = 0,
		hi = idx;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(left[mid] - left[0] + a * mid <= pool)
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

int rightans(LL pool, int idx){
	int lo = idx,
		hi = n;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(right[mid] + (n - mid) * a <= pool)
			hi = mid;
		else
			lo = mid;
	}
	return n - hi;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b >> T;
	cin >> s;
	left[0] = 1 + (s[0] == 'w') * b;
	for(int i = 1; i < n; i++)
		left[i] = left[i - 1] + 1 + (s[i] == 'w') * b;
	right[n - 1] = 1 + (s[n - 1] == 'w') * b;
	for(int i = n - 2; i >= 0; i--)
		right[i] = right[i + 1] + 1 + (s[i] == 'w') * b;
	LL ans = 0;
	for(int i = 0; i < n; i++){
		LL minu = left[i] + i * a;
		if(minu > T)
			break;
		smax(ans, i + 1);
		minu += i * a;
		if(minu <= T)
			smax(ans, i + 1 + rightans(T - minu, i));
	}
	for(int i = n - 1; i > 0; i--){
		LL minu = right[i] + (n - i) * a + left[0];
		if(minu > T)
			break;
		smax(ans, n - i + 1);
		minu += (n - i) * a;
		if(minu <= T)
			smax(ans, n - i + 1 + leftans(T - minu, i));
	}
	cout << ans << endl;
	return 0;
}