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

const int maxn = 3e5 + 85 - 69;
int sum[maxn],
	n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		sum[i + 1] = sum[i] + 1 - x;
	}
	int ptr = 0,
		ans = 0,
		lans, rans;
	for(int i = 0; i <= n; i++){
		while(sum[i] - sum[ptr] > k) ptr++;
		if(i - ptr >= ans){
			ans = i - ptr;
			lans = ptr + 1;
			rans = i;
		}
	}
	cout << ans << endl;
	for(int i = 1; i < lans; i++)
		cout << 1 - sum[i] + sum[i - 1] << ' ';
	for(int i = lans; i <= rans; i++)
		cout << 1 << ' ';
	for(int i = rans + 1; i <= n; i++)
		cout << 1 - sum[i] + sum[i - 1] << ' ';
	cout << endl;
	return 0;
}