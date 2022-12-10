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

const int maxn = 1e5 + 85 - 69;
LL a[maxn],
   sum[maxn],
   ord[maxn];
int n;
set<pii> s;
multiset<LL> ms;

void shiaf(int l, int r){
	ms.insert(sum[r + 1] - sum[l]);
	s.insert(MP(r, l));
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], sum[i + 1] = sum[i] + a[i];
	for(int i = 0; i < n; i++)
		cin >> ord[i], ord[i]--;
	ms.insert(0);
	shiaf(0, n - 1);
	for(int i = 0; i < n; i++){
		auto it = s.lower_bound(MP(ord[i], -1));
		pii seg(it->R, it->L);
		ms.erase(ms.lower_bound(sum[seg.R + 1] - sum[seg.L]));
		s.erase(it);
		shiaf(seg.L, ord[i] - 1);
		shiaf(ord[i] + 1, seg.R);
		cout << *ms.rbegin() << '\n';
	}
	return 0;
}