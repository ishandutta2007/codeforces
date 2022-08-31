#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;

const int N = 1e6 + 7;

void no() {
	cout << "no" << endl, exit(0);
}

int n, a[N];
vi vc[N], G;

bool ok = true;
int nxt[N], stk[N], tp;
void solve(int l, int r) {
//	cout << l << ' ' << r << endl;
	if((r - l) & 1) return no();
	if(l > r) return ; 
	int w = a[l];
	if(a[l] && a[r] && a[l] != a[r]) no();
	if(!w) w = a[r];
	
	if(l == 1 && r == n * 2 - 1 && w) {
		a[l] = a[r] = w;
		if(vc[w].back() != r) vc[w].push_back(r);
		if(vc[w][0] != l) vc[w].insert(vc[w].begin(), l);
		if(sz(vc[w]) != 2) {
			L(i, 1, sz(vc[w]) - 1) solve(vc[w][i - 1], vc[w][i]);
			return ;
		}
	} 
	
//	L(i, l, r) cout << a[i] << ' ';
//	cout << endl;
	
	int cnt = !!a[l], all = 1;
	for(int i = l + 1; i < r; ++i) if(a[i]) {
		if(vc[a[i]][0] != i || vc[a[i]].back() > r) no();
		L(j, 1, sz(vc[a[i]]) - 1) solve(vc[a[i]][j - 1], vc[a[i]][j]);
		i = vc[a[i]].back(), cnt += 1, all += 1;
	} else all += 1;
	
	cnt = all / 2 + 1 - cnt;
	
//	cout << "cnt = " << all << ' ' << cnt << endl;
	
	if(cnt < 0) no();
	
//	L(i, l, r) cout << a[i] << ' ';
//	cout << endl;
	
	auto pb = [&] (int x) {
//		cout << "qwq" << endl;
		if(!a[x] && cnt) {
			if(!sz(G)) no();
			a[x] = G.back(), --cnt, G.pop_back();
		}
//		cout << "pb " << a[x] << endl; 
		if(tp > 1 && a[stk[tp]] && a[stk[tp - 1]]) {
			if(a[x]) stk[++tp] = x;
			else a[x] = a[stk[tp - 1]], --tp;
		} else {
//			cout << "never gonna " << endl;
			stk[++tp] = x;
			while(tp > 2 && a[stk[tp - 1]] && a[stk[tp]]) 
				assert(!a[stk[tp - 2]]), a[stk[tp - 2]] = a[stk[tp]], tp -= 2;
//			cout << "give u up" << endl;
		}
	};
	
	tp = 0, pb(l);
	for(int i = l + 1, t; i < r; i = t ? vc[t].back() + 1 : i + 1) t = a[i], pb(i);
	pb(r);
}

int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	
	cin >> n;
	L(i, 1, n * 2 - 1) cin >> a[i], a[i] ? vc[a[i]].push_back(i) : void();
	R(i, n, 1) if(!sz(vc[i])) G.emplace_back(i); 
	solve(1, n * 2 - 1);
	a[0] = a[n * 2] = -1;
	
	cout << "yes\n";
	L(i, 1, n * 2 - 1) cout << a[i] << ' ';
	return 0;
}