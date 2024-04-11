#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;

const int N = 1e6 + 7;

int n;

string a, b, c;

int ca[26], cb[26], cc[26];
int pc[26][26];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	
	me(pc, 0), me(ca, 0), me(cb, 0), me(cc, 0);
	L(i, 0, sz(a) - 1) {
		ca[a[i] - 'A'] += 1;
	} 
	L(i, 0, sz(b) - 1) {
		cb[b[i] - 'A'] += 1;
	} 
	L(i, 0, sz(c) - 1) {
		cc[c[i] - 'A'] += 1;
	} 
	vi gt, gb, gc;
	L(i, 0, 25) {
		int lenb = min(cb[i], ca[i]);
		int lenc = min(cc[i], ca[i]);
		int mand = max(lenb + lenc - ca[i], 0);
		L(t, 1, mand) {
			if(cb[i] - lenb < cc[i] - lenc) --lenb;
			else --lenc;
		}
		cb[i] -= lenb, cc[i] -= lenc;
		L(j, 1, lenc) gb.push_back(i);
		L(j, 1, lenb) gc.push_back(i);
		L(j, 1, ca[i] - lenb - lenc) gt.push_back(i);
	}
	L(i, 0, 25) while(cb[i] && cc[i] && sz(gt)) 
		pc[gt.back()][i] += 1, gt.pop_back(), --cb[i], --cc[i];
	
	L(i, 0, 25) while(cb[i] && sz(gb)) pc[gb.back()][i] += 1, --cb[i], gb.pop_back();
	L(i, 0, 25) while(cc[i] && sz(gc)) pc[gc.back()][i] += 1, --cc[i], gc.pop_back();
	
	for(const int &i : gb) pc[i][i] += 1;
	for(const int &i : gc) pc[i][i] += 1;
	
	vi nb, nc;
	L(i, 0, 25) L(j, 1, cb[i]) nb.push_back(i);
	L(i, 0, 25) L(j, 1, cc[i]) nc.push_back(i);
	
	for(const int &i : gt) { 
		if(sz(nb) > sz(nc)) pc[i][nb.back()] += 1, nb.pop_back();
		else if(sz(nc)) pc[i][nc.back()] += 1, nc.pop_back();
		else pc[i][i] += 1;
	}
	
	while(sz(nb) < sz(nc)) nb.push_back(0);
	while(sz(nc) < sz(nb)) nc.push_back(0);
	
	L(i, 0, sz(nb) - 1) pc[nb[i]][nc[i]] += 1;
	int cnt = 0;
	L(i, 0, 25) L(j, 0, 25) cnt += pc[i][j];
	cout << cnt << '\n';
	L(i, 0, 25) L(j, 0, 25) L(k, 1, pc[i][j])
		cout << ((char) (i + 'A')) << ((char) (j + 'A')) << '\n';
	return 0; 
}
/*
 (abc,{})  (ab,c)  
 (ab,c)  (ac,b) (a,bc)  

 (ab,c) + (ac,b)  
 (bc)  
*/