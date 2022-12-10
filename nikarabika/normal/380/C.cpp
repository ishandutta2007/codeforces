#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;
typedef pair<int, pie> piie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e6 + 85 - 69;
piie seg[maxn * 4];
string s;
int m;

piie make(int L = 0, int R = s.size(), int id = 1){
	if(R - L == 1){
		if(s[L] == '(')
			seg[id].R.L = 1;
		else
			seg[id].R.R = 1;
		return seg[id];
	}
	int mid = (L + R) >> 1;
	piie inter1, inter2;
	inter1 = make(L, mid, id * 2 + 0);
	inter2 = make(mid, R, id * 2 + 1);
	int match = min(inter1.R.L, inter2.R.R);
	seg[id].L = inter1.L + inter2.L + match;
	seg[id].R.L = inter1.R.L + inter2.R.L - match;
	seg[id].R.R = inter1.R.R + inter2.R.R - match;
	return seg[id];
}

piie get(int l, int r, int L = 0, int R = s.size(), int id = 1){
	if(l == L and r == R)
		return seg[id];
	int mid = (L + R) >> 1;
	piie inter1 = MP(0, MP(0, 0)), inter2 = MP(0, MP(0, 0)), here;
	if(l < mid) 
		inter1 = get(l, min(mid, r), L, mid, id * 2 + 0);
	if(r > mid)
		inter2 = get(max(l, mid), r, mid, R, id * 2 + 1);
	int match = min(inter1.R.L, inter2.R.R);
	here.L = inter1.L + inter2.L + match;
	here.R.L = inter1.R.L + inter2.R.L - match;
	here.R.R = inter1.R.R + inter2.R.R - match;
	return here;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	make();
	cin >> m;
	while(m--){
		int fi, se;
		cin >> fi >> se;
		cout << 2 * get(fi - 1, se).L << '\n';
	}
	return 0;
}