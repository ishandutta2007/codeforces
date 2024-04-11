#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;

const int N = 5e5 + 7;

int n;
//string rns = "HHHHHHHHHHHHHH";
vi query(string s) {
//	vi S;
//	L(i, 0, sz(rns) - sz(s)) {
//		bool ok = true; 
//		L(j, 0, sz(s) - 1) 
//			if(s[j] != rns[i + j]) 
//				ok = false;
//		if(ok) S.emplace_back(i + 1);
//	}
	cout << "? " << s << endl;
	int k, x;
	vi S;
	cin >> k;
	L(i, 1, k) cin >> x, S.emplace_back(x);
	return S;
}
bool chk(vi s, int o) {
	for(const int &u : s) 
		if(u == o) 
			return true;
	return false;
}
string f[4] = {"CH", "CO", "HC", "HO"}, qwq;
char ns[N];
void Main() {
	bool ok = false;
	cin >> n;
//	n = sz(rns);
	vi o, to;
	L(i, 1, n + 1) ns[i] = 0;
	L(i, 0, 3) {
		o = query(f[i]);
		if(sz(o)) {
			ok = true;
			for(const int &u : o) 
				ns[u] = f[i][0], ns[u + 1] = f[i][1];
		}
	} 
	if(ok) {
		int pos = -1;
		L(i, 1, n) if(ns[i]) {
			pos = i;
			break ;
		}
		assert(pos > 0);
		R(i, pos, 2) {
			if(ns[i] == 'O') ns[i - 1] = 'O';
			else {
				string all;
				all.push_back(ns[i]);
				L(j, i, pos + 1) all.push_back(ns[j]);
				ns[i - 1] = chk(query(all), i - 1) ? ns[i] : 'O';
			}
		}
		L(i, pos, n) if(!ns[i]) {
			if(ns[i - 1] == 'O') {
				string all;
				L(j, 1, i - 1) all.push_back(ns[j]);
				all.push_back('O');
				if(chk(query(all), 1)) {
					ns[i] = 'O';
				} else {
					string all;
					L(j, 1, i - 1) all.push_back(ns[j]);
					all.push_back('C');
					ns[i] = chk(query(all), 1) ? 'C' : 'H';
				}
			} else {
				ns[i] = ns[i - 1];
			}
		}
		cout << "! " << (ns + 1) << endl;
	} else {
		vi o = query("OOO");
		if(sz(o)) {
			string nsa, nsb ;
			L(i, 1, sz(o) + 2) nsa.push_back('O'), nsb.push_back('O');
			while(sz(nsa) < n) nsa.push_back('C'), nsb.push_back('H');
			if(sz(query(nsa))) cout << "! " << nsa << endl;
			else cout << "! " << nsb << endl;
		} else {
			vi c = query("CCC");
			vi h = query("HHH");
			string xns; 
			if(sz(c)) {
				L(i, 1, n - sz(c) - 2) xns.push_back('O');
				L(i, 1, sz(c) + 2) xns.push_back('C');
				cout << "! " << xns << endl;
			} else if(sz(h)) {
				L(i, 1, n - sz(h) - 2) xns.push_back('O');
				L(i, 1, sz(h) + 2) xns.push_back('H');
				cout << "! " << xns << endl;
			} else {
				assert(n == 4);
				if(sz(query("OOCC"))) cout << "! OOCC" << endl;
				else cout << "! OOHH" << endl;
			}
		}
	}
	int w;
	cin >> w;
}

int main () {
//	Main();
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}