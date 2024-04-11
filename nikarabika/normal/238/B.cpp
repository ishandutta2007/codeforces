//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
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

const int maxn = 1e5;
int a[maxn], ord[maxn];

bool cmp(int i, int j){
	return a[i] < a[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, h;
	cin >> n >> h;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	iota(ord, ord + n, 0);
	sort(ord, ord + n, cmp);
	LL ans1, ans2;
	if(n == 2){
		cout << 0 << endl
			<< "1 2" << endl;
		return 0;
	}
	ans1 = max(a[ord[n - 1]] + a[ord[n - 2]], a[ord[n - 1]] + a[ord[0]] + h) - min(a[ord[1]] + a[ord[0]] + h, a[ord[1]] + a[ord[2]]);
	ans2 = a[ord[n - 1]] + a[ord[n - 2]] - a[ord[0]] - a[ord[1]];
	if(ans1 < ans2){
		cout << ans1 << '\n';
		for(int i = 0; i < n; i++)
			cout << 1 + (ord[0] == i) << ' ';
		cout << '\n';
	}
	else{
		cout << ans2 << '\n';
		for(int i = 0; i < n; i++)
			cout << 1 << ' ';
		cout << endl;
	}
	return 0;
}