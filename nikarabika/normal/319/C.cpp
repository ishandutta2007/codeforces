//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const int maxn = 1e5 + 85 - 69;
LL dp[maxn],
   a[maxn],
   b[maxn];
int stc[maxn],
	n, sz;

LD inters(int l1, int l2){
	return LD(dp[l2] - dp[l1]) / LD(b[l1] - b[l2]);
}

void add(int id){
	while(sz > 1 and inters(stc[sz - 2], id) < inters(stc[sz - 1], stc[sz - 2]))
		sz--;
	stc[sz++] = id;
	return;
}

LL get(int x){
	int lo = 0, hi = sz;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(x < inters(stc[mid - 1], stc[mid]))
			hi = mid;
		else
			lo = mid;
	}
	return x * b[stc[lo]] + dp[stc[lo]];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 1; i < n; i++){
		add(i - 1);
		dp[i] = get(a[i]);
	}
	cout << dp[n - 1] << '\n';
	return 0;
}