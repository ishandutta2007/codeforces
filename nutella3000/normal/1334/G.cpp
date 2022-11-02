#include <bits/stdc++.h>
using namespace std;
 
//#define int long long
#define pii pair<int, int>
//#define sz(a) ((int)a.size())  
typedef long double ld;
 
 
const int inf = 1e9 + 7;
const int log_n = 20;
const int N = (1 << log_n);
const ld Eps = 0.001;
const ld PI = acos(-1.0);
 
struct comp {
	ld r, c;
 
	comp(ld r = 0.0, ld c = 0.0) : r(r), c(c) {}
};
 
inline comp operator +(const comp &a,const comp &b) {
	return comp(a.r + b.r, a.c + b.c);
}
 
inline comp operator -(const comp &a,const comp &b) {
	return comp(a.r - b.r, a.c - b.c);
}
 
inline comp operator *(const comp &a,const  comp &b) {
	return comp(a.r * b.r - a.c * b.c, a.r * b.c + a.c * b.r);
}
 
inline comp operator /(const comp &a,const ld &b) {
	return comp(a.r / b, a.c / b);
}
 
 
vector<comp> w[log_n + 1];
int ord[N]; 

void precalc() {
	for(int k = 0;k <= log_n;k++) {
		w[k].resize((1 << k));
		w[k][0] = comp(1, 0);
 
		ld ang = 2 * PI / (1 << k);

		if (k == 0) continue;

		w[k][1] = comp(cos(ang), sin(ang));
 
		for(int i = 2;i < (1 << k);i++) w[k][i] = w[k][i - 1] * w[k][1];
	}

	for(int k = 0;k < N;k++) {
		int num = 0;
		for(int i = 0;i < log_n;i++) {
			if (k & (1 << i)) num += (1 << (log_n - i - 1));
		}

		ord[k] = num;
		//cout << num << endl;
	}
}
 
 
vector<comp> fft(vector<comp> a) {
	for(int i = 0;i < N;i++) {
		if (ord[i] > i) {
			swap(a[i], a[ord[i]]);
		}
	}


	for(int sz = 1;sz <= log_n;sz++) {
		int len = (1 << (sz - 1));
		for(int bl = 0;bl < N;bl += len * 2) {
			for(int i = bl;i < bl + len;i++) {
				comp one = a[i];
				comp two = w[sz][i - bl] * a[i + len];

				a[i] = one + two;
				a[i + len] = one - two;
			}
		}
	}
 
	return a; 
}
 
 
vector<comp> rev_fft(vector<comp> a) {
	a = fft(a);
	vector<comp> b(a.size());
	for(int i = 0;i < N;i++) b[i] = a[(N - i) % N] / N;
 
	return b;
}
 
bitset<N> f(vector<comp> a, vector<comp> b, ld sum) {
	int rev_sz = N;
	for(int i = 0;i < rev_sz / 2;i++) swap(b[i], b[rev_sz - i - 1]);
	
	a = fft(a);
	//cout << "aaa" << endl;
	b = fft(b);
 
	for(int i = 0;i < N;i++) a[i] = a[i] * b[i];
 
	a = rev_fft(a);
	
	//cout << "hood" << endl;


	bitset<N> res;
 
	for(int i = 0;i < rev_sz;i++) res[i] = a[rev_sz - i - 1].r >= sum - Eps;
 
	return res;
}
 
 
bitset<N> p_function(vector<int> a, vector<int> b) {
	int n1 = a.size(), n2 = b.size();
	a.emplace_back(-1);
	for(int i : b) a.emplace_back(i);
	
	vector<int> p(a.size());
 
	for(int i = 1;i < a.size();i++) {
		int j = p[i - 1];
		while(j > 0 && a[j] != a[i]) j = p[j - 1];
		if (a[i] == a[j]) j++;		
		p[i] = j; 
	}
 
	bitset<N> res(false);
 
	int id = 0;
	for(int i = 2 * n1;i < a.size();i++) res[id++] = p[i] == n1;
 
	return res;
}
 
 
 
void solve() {
	precalc();
 
	vector<int> p(26), com(26), ind(26), sz(26);
	string s, t;
	for(int i = 0;i < 26;i++) {
		cin >> p[i];
		p[i]--;
	}
 
	cin >> s >> t;
 
	int temp = 1;
	for(int i = 0;i < 26;i++) {
		if (com[i] == 0) {
			int v = i;
			int temp1 = 0;
			while(!com[v]) {
				com[v] = temp;
				ind[v] = temp1++;
				v = p[v];
			}
 
			v = i;
			do{
				sz[v] = temp1;
				v = p[v];
			}while(v != i);
 
			temp++;
		}
	}
 
	vector<int> s1(s.size()), t1(t.size());
 
	for(int i = 0;i < s.size();i++) s1[i] = com[s[i] - 'a'];
	for(int i = 0;i < t.size();i++) t1[i] = com[t[i] - 'a'];
 
	bitset<N> res = p_function(s1, t1);
	
	vector<comp> s2(N), t2(N);
 
	ld sum = 0;
 
	for(int i = 0;i < s.size();i++) {
		ld ang = PI / sz[s[i] - 'a'];
 
		sum += cos(ang);
 
		ang = ang * 2 * ind[s[i] - 'a'];
		s2[i] = comp(cos(ang), sin(ang));
	}
 	
 	//cout << s2[1].r << endl;

	for(int i = 0;i < t.size();i++) {
		ld ang = (PI - 2 * PI * ind[t[i] - 'a']) / sz[t[i] - 'a'];
		t2[i] = comp(cos(ang), sin(ang));
	}
 
	res &= f(s2, t2, sum);
 
	for(int i = 0;i < t.size() - s.size() + 1;i++) cout << res[i];
}
 
 
 
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);
 
   	solve();
 
}