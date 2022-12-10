//sobskdrbhvk
//remember the flight, the bird dies ):(
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
int a[maxn],
	d[maxn],
	ord[maxn],
	lst[maxn],
	orga[maxn],
	n, m;
bool mark[maxn];

bool cmp(int i, int j){
	return lst[i] < lst[j];
}

bool solve(int n){
	memset(mark, false, sizeof mark);
	memset(lst, -1, sizeof lst);
	for(int i = 0; i < n; i++)
		lst[d[i]] = i;
	for(int i = 0; i < m; i++)
		mark[lst[i]] = true;
	memcpy(a, orga, sizeof orga);
	iota(ord, ord + m, 0);
	sort(ord, ord + m, cmp);
	int ptr = 0,
		pass = 0;
	for(int i = 0; i < n; i++){
		if(mark[i]){
			if(a[d[i]] == 0){
				pass++;
				if(pass == m){
					return true;
				}
				continue;
			}
			else
				return false;
		}
		if(ptr < m){
			a[ord[ptr]]--;
			if(a[ord[ptr]] == 0)
				ptr++;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> d[i], d[i]--;
	for(int i = 0; i < m; i++)
		cin >> orga[i];
	int lo = 0,
		hi = n + 1;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(solve(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << (hi == n + 1 ? -1 : hi) << '\n';
	return 0;
}