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

const int maxn = 200000 + 85 - 69;
LL a[maxn], sum[maxn], n;

LD func(int md, int len){
	return LD(sum[md + 1] - sum[md - len] + sum[n] - sum[n - len]) / LD(2 * len + 1) - a[md];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + a[i];
	LD Max = -1;
	pii ans(-1, -1);
	for(LL i = 0; i < n; i++){
		int lo = 0, hi = min(i, n - i - 1);
		while(hi - lo > 6){
			int mid1 = (lo + lo + hi) / 3,
				mid2 = (lo + hi + hi) / 3;
			if(func(i, mid1) > func(i, mid2))
				hi = mid2;
			else
				lo = mid1;
		}
		for(int j = lo; j <= hi; j++){
			LD val = func(i, j);
			if(val > Max)
				Max = val, ans = {i, j};
		}
	}
	//cout << Max << ' ' << func(1, 1) << ' ' << func(0, 0) << endl;
	cout << 2 * ans.R + 1 << '\n';
	for(int i = ans.L - ans.R; i <= ans.L; i++)
		cout << a[i] << ' ';
	for(int i = n - ans.R; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
	return 0;
}