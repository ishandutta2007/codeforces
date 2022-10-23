#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
using namespace std;
const int N = 1 << 20;
int op; 
vi slv(int n) {
	if(n == 1 && op == 1) {
		return {1, 2}; 
	}
	if(n == 2 && op == 2) {
		vi ns;
		ns.push_back(1);
		ns.push_back(7);
		ns.push_back(2);
		ns.push_back(4);
		ns.push_back(6);
		ns.push_back(5);
		ns.push_back(3);
		ns.push_back(8);
		return ns;
	}
	if(n == 1) {
		return {1};
	}
	vi t = slv(n - 1);
	if(sz(t) % 2 == 0) {
		vi ns;
		L(i, 0, sz(t) - 1) 
			ns.push_back(t[i] * 2 + (i & 1));
		ns.push_back(1);
		L(i, 0, sz(t) - 1) 
			ns.push_back(t[i] * 2 + !(i & 1));
		reverse(ns.begin(), ns.end());
//		cout << "qwq" << endl;
		return ns;
	}
	vi ns;
	ns.push_back({1});
	L(i, 0, sz(t) - 1) 
		ns.push_back(t[i] * 2 + !(i & 1));
	L(i, 0, sz(t) - 1) 
		ns.push_back(t[sz(t) - i - 1] * 2 + (i & 1));
	reverse(ns.begin(), ns.end());
	return ns;
}
vi q1(int n) {
	if(n == 2) return vi {2 * 2 + 0, 1 * 2 + 1, 3 * 2 + 0, 1 * 2 + 0, 2 * 2 + 1, 0 * 2 + 1, 3 * 2 + 1};
	vi t = q1(n - 1), ns;
	int o = 1;
	L(i, 0, sz(t) - 1) ns.emplace_back(t[i] * 2 + o), o ^= 1;
	ns.emplace_back(1);
	L(i, 0, sz(t) - 1) ns.emplace_back(t[i] * 2 + o), o ^= 1;
	int qt = (1 << (n - 1));
	L(i, 0, sz(ns) - 1) if(ns[i] == 1 || ns[i] == qt) ns[i] ^= 1 ^ qt; 
	return ns;
}

int n, w[N], f[N], cm[N];
struct qwq {
	int w, k;
} q[N];
int mp[N], prd;
void Main() {
	cin >> n, prd = 1;
	L(i, 1, n) cin >> w[i], prd *= w[i] + 1;
	L(i, 0, prd) mp[i] = 0;
	L(i, 1, n) q[i].w = w[i], q[i].k = i;
	sort(q + 1, q + n + 1, [&] (qwq a, qwq b) {
		return a.w > b.w;
	});
	L(i, 1, n) w[i] = q[i].w;
	if(w[1] > 3) return cout << "-1\n", void();
	if(n > 1 && w[2] > 2) return cout << "-1\n", void();
	
	vi o;
	if(w[1] == 3) {
		if(n == 1) {
			cout << 2 << '\n' << 1 << '\n' << 3 << '\n';
			return;	
		}
		if(w[2] > 1) {
			cout << -1 << '\n';
			return ;
		}
		o = q1(n);
	} else {
		op = 0;
		while(op < n && w[op + 1] == 2) ++op;
		if(op > 2) {
			cout << "-1\n";
			return ;
		}
		o = slv(n);
	}
	L(i, 0, sz(o) - 1) {
		int cur = o[i];
		if(mp[cur]) assert(false);
		mp[cur] = 1;
		R(j, n, 1) f[q[j].k] = cur % (w[j] + 1), cur /= w[j] + 1;
		int cnt = 0;
		L(j, 1, n) cout << f[j] << ' ', cnt += min(f[j], cm[j]), cm[j] = f[j];
		cout << "\n";
		if(i > 0) assert(cnt == 1);
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main(); 
	return 0;
}
/*
2
2
3 1
3
3 1 1

3 1 0 0
0 1 1 1
2 1 0 0
0 1 0 1
3 1 1 0
0 0 1 1
2 1 1 0
0 1 0 0
3 1 0 1
0 1 1 0
2 1 0 1
0 0 0 1
3 1 1 1
0 0 1 0
2 1 1 1

Reversal.  

1 0 1
3 0 0
1 1 1
2 0 0
1 0 0
3 0 1
1 1 0
2 0 1

1 0 0 
1 0 2
0 1 1
1 1 0 
0 1 2
1 0 1
0 0 2
1 1 1
0 1 0 
1 1 2
0 0 1

0 1
2 1
0 2
1 1
2 0
1 2
1 0
2 2

1 - 000
1 - 001
0 - 101
1 - 110
0 - 011
1 - 010
0 - 111
1 - 100 
0 - 100
1 - 111
0 - 010
1 - 011
0 - 110
1 - 101
0 - 001
 
*/