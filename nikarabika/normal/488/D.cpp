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

const int maxn = 100 * 1000 + 85 - 69,
	  maxl = 20,
	  Inf = 1000 * 1000 * 1000;
int sptn[maxn][maxl],
	sptx[maxn][maxl],
	spp[maxn],
	seg[maxn * 4],
	n, maxD, minL;

int getmin(int st, int en){
	int lg = spp[en - st + 1];
	return min(sptn[st][lg], sptn[en - (1 << lg) + 1][lg]);
}

int getmax(int st, int en){
	int lg = spp[en - st + 1];
	return max(sptx[st][lg], sptx[en - (1 << lg) + 1][lg]);
}

void modify(int idx, int val, int l = 0, int r = n, int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		seg[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	modify(idx, val, l, mid, id * 2 + 0);
	modify(idx, val, mid, r, id * 2 + 1);
	seg[id] = min(seg[id * 2 + 0], seg[id * 2 + 1]);
	return;
}

int get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return Inf;
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return min(get(st, en, l, mid, id * 2 + 0),
			get(st, en, mid, r, id * 2 + 1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	spp[0] = -1;
	for(int i = 1; i < maxn; i++)
		spp[i] = spp[i>>1] + 1;
	cin >> n >> maxD >> minL;
	for(int i = 0; i < n; i++)
		cin >> sptn[i][0], sptx[i][0] = sptn[i][0];
	for(int j = 1; j < maxl; j++)
		for(int i = 0; i + (1 << j) <= n; i++)
			sptn[i][j] = min(sptn[i][j - 1], sptn[i + (1 << (j - 1))][j - 1]),
				sptx[i][j] = max(sptx[i][j - 1], sptx[i + (1 << (j - 1))][j - 1]);
	for(int i = 0; i < n; i++){
		if(i < minL - 1){
			modify(i, Inf);
			continue;
		}
		if(getmax(0, i) - getmin(0, i) <= maxD)
			modify(i, 1);
		else{
			int lo = 0, hi = i;
			while(hi - lo > 1){
				int mid = (lo + hi) >> 1;
				if(getmax(mid, i) - getmin(mid, i) <= maxD)
					hi = mid;
				else
					lo = mid;
			}
			if(lo >= i - minL + 1)
				modify(i, Inf);
			else
				modify(i, get(lo, i - minL + 1) + 1);
		}
	}
	int val = get(n - 1, n);
	cout << (val >= Inf ? -1 : val) << endl;
	return 0;
}