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
   b[maxn];
int n, m;

bool cango(LL st, LL lef, LL rig, LL tim){
	if(lef >= st)
		return rig - st <= tim;
	if(rig <= st)
		return st - lef <= tim;
	return min(2 * (st - lef) + rig - st, (rig - st) * 2 + st - lef) <= tim;
}

bool check(LL tim){
	int ptr = 0;
	for(int i = 0; i < n; i++){
		int pt = ptr;
		while(ptr < m and cango(a[i], b[pt], b[ptr], tim))
			ptr++;
	}
	return ptr == m;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];
	LL lo = -1,
	   hi = 1000LL * 1000 * 1000 * 100;
	while(hi - lo > 1){
		LL mid = (lo + hi) >> 1;
		if(check(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << '\n';
	return 0;
}