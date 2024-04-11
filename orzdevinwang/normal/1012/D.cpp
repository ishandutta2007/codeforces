#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int n, lens[N], ops[N], tps;
int m, lent[N], opt[N], tpt;
char s[N], t[N];
vector < pair < int, int > > ns;
void make (int x, int y) { // O (x + y)
	vector < pair < int, int > > s, t;
	int allx = 0, ally = 0;
	L(i, tps - x + 1, tps) s.push_back({ops[i], lens[i]}), allx += lens[i];
	L(i, tpt - y + 1, tpt) t.push_back({opt[i], lent[i]}), ally += lent[i];
	tps -= x, tpt -= y;
	for (auto u : s) {
		if(tpt && u.first == opt[tpt]) lent[tpt] += u.second;
		else ++tpt, opt[tpt] = u.first, lent[tpt] = u.second;
	}
	for (auto u : t) {
		if(tps && u.first == ops[tps]) lens[tps] += u.second;
		else ++tps, ops[tps] = u.first, lens[tps] = u.second;
	}
	ns.push_back({allx, ally});
	// L(j, 1, tps) cout << lens[j] << ' ' << ops[j] << '\n';
	// cout << '\n';
	// L(j, 1, tpt) cout << lent[j] << ' ' << opt[j] << '\n';
	// cout << '\n';
}
void work () {
	assert (tps >= tpt);
	if(ops[1] == opt[1]) {
		if((tps + tpt) % 2 == 1) {
			if((tps - tpt) % 4 == 1) {
				make ((tps + tpt) / 2, tpt);
			}
			else {
				if(tpt == 1) {
					make (1, 0);
					make ((tps + tpt) / 2, tpt);
				}
				else {
					make ((tps - tpt + 3) / 2, 1);
					make (tps, tps);
				}
			}
		}
		else {
			if(tpt == 1) {
				if(tps == 3) {
					make (1, 0);
					make (1, 1);
				}
				else {
					if((tps - tpt) % 4 == 2) make (1, 0);
					else make(2, 1);
				}
			}
			else {
				if((tps - tpt) % 4 == 2) {
					make (1, 0);
					make ((tps + tpt) / 2, tpt);
				}
				else {
					make (0, 1);
					make((tps + tpt) / 2, tpt);
				}
			}
		}
		return ;
	}
	if(tps == tpt) return make(1, 1), void (); 
	if((tps + tpt) % 2 == 1) {
		if((tps - tpt) % 4 == 1) make ((tps - tpt + 1) / 2, 0);
		else if(tpt == 1) make ((tps - tpt - 1) / 2, 0), make (1, 0);
		else make (2, 1);
	}
	else if(tpt == 1) make((tps - 1) / 2, 0);
	else make((tps - tpt) / 2 + 1, 1);
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> (s + 1) >> (t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	reverse(s + 1, s + n + 1);
	reverse(t + 1, t + m + 1);
	L(i, 1, n) {
		if(!tps || ops[tps] != s[i] - 'a') ++ tps, lens[tps] = 1, ops[tps] = s[i] - 'a';
		else lens[tps] += 1;
	}
	L(i, 1, m) {
		if(!tpt || opt[tpt] != t[i] - 'a') ++ tpt, lent[tpt] = 1, opt[tpt] = t[i] - 'a';
		else lent[tpt] += 1;
	}

	bool wap = false;
	if(tps < tpt) 
		wap = true, swap (lens, lent), swap (ops, opt), swap(tps, tpt);

	// if(n >= 1000) {
	// 	cout << tps << ' ' << tpt << '\n';
	// 	cout << ops[1] << ' ' << opt[1] << '\n';
	// }

	while (tps > 1 || tpt > 1) 
		work ();

	cout << sz(ns) << '\n';
	for (auto u : ns) 
		if(!wap) 
			cout << u.first << ' ' << u.second << '\n';
		else 
			cout << u.second << ' ' << u.first << '\n';
	return 0;
}
/*
bababa
ab

*/