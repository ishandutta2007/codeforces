#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define has(set, x) set.find(x) != set.end()
#define nohas(set, x) set.find(x) == set.end()
#define inc(mpp, x) {if(has(mpp, x)) mpp[x]++; else mpp.insert(mp(x,1));}
#define decc(mpp, x) {if(has(mpp, x)) {if(mpp[x] > 1) mpp[x]--; else mpp.erase(x);}}
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define um unordered_map
#define us unordered_set
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <stack>
#include <numeric>
#include <queue>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }

const int sz = 1e5 + 5;
string s;
int to[10][sz];
int n;
struct cust{
	int a=0, t=0, g=0, c=0;
	cust(){}
	cust(int z) {
		a = z;
		t = z;
		g = z;
		c = z;
	}
	cust(char cc) {
		switch (cc) {
		case 'A':
			a = 1;
			break;
		case 'T':
			t = 1;
			break;
		case 'G':
			g = 1;
			break;
		case 'C':
			c = 1;
			break;
		}
	}
	cust operator+(cust& other) {
		cust res;
		res.a = this->a + other.a;
		res.t = this->t + other.t;
		res.g = this->g + other.g;
		res.c = this->c + other.c;
		return res;
	}
};

pii leftRight(int l, int r, int md, int  rem) {
	pii ans;
	if (l%md == rem)ans.first = l;
	else if ((l / md)*md + rem > l)ans.first = (l / md)*md + rem;
	else ans.first = (l / md + 1)*md + rem;
	if (r%md == rem)ans.second = r;
	else if ((r / md)*md + rem < r)ans.second = (r / md)*md + rem;
	else ans.second = (r / md - 1)*md + rem;
	return ans;
}

template<class T>
struct segmentree {
	vector<T> segment;
	int size;
	segmentree(vector<T> arr) {
		size = arr.size();
		segment.resize(2 * size);
		for (int k = 0; k < size; k++)
			segment[size + k] = arr[k];
		for (int k = size - 1; k > 0; k--)
			segment[k] = segment[2 * k] + segment[2 * k + 1];
	}
	void update(int index, T val) {
		int t = index + size;
		segment[t] = val;
		while (t > 1) {
			t >>= 1;
			segment[t] = segment[2 * t] + segment[2 * t + 1];
		}
	}
	T query(int fromIncluded, int toNotIncluded) {
		T sum(0);
		fromIncluded += size;
		toNotIncluded += size;
		while (fromIncluded < toNotIncluded) {
			if (fromIncluded % 2 == 1) {
				sum = sum + segment[fromIncluded];
				fromIncluded++;
			}
			if (toNotIncluded % 2 == 1) {
				sum = sum + segment[toNotIncluded - 1];
				toNotIncluded--;
			}
			fromIncluded /= 2;
			toNotIncluded /= 2;
		}
		return sum;
	}
};

vector<segmentree<cust>> prep() {
	foru(e, 0, 10) {
		int curr = 0;
		foru(md, 0, e+1) {
			for (int start = md; start < n; start += (e+1)) {
				to[e][start] = curr;
				curr++;
			}
		}
	}
	vector<segmentree<cust>> arr;
	foru(e, 0, 10) {
		vector<cust> tmp(n);
		foru(i, 0, n) {
			switch (s[i]) {
			case 'A':
				tmp[to[e][i]].a = 1;
				break;
			case 'G':
				tmp[to[e][i]].g = 1;
				break;
			case 'T':
				tmp[to[e][i]].t = 1;
				break;
			case 'C':
				tmp[to[e][i]].c = 1;
				break;
			}
		}
		arr.pb(segmentree<cust>(tmp));
	}
	return arr;
}

int main() {
	fast;
	cin >> s;
	n = s.length();
	vector<segmentree<cust>> arr = prep();
	int q,qtype,l,r,i;
	char tmpc;
	string tmpstr;
	cin >> q;
	while (q--) {
		cin >> qtype;
		switch (qtype) {
		case 1:
			cin >> i >> tmpc; i--;
			foru(e, 0, 10) {
				arr[e].update(to[e][i], cust(tmpc));
			}
			break;
		case 2:
			cin >> l >> r >> tmpstr;
			int e = tmpstr.length(), tot = 0;
			l--; r--;
			foru(i, 0, e) {
				int rem = (l + i) % e;
				pii p = leftRight(l, r, e, rem);
				if (p.first > p.second)continue;
				int ll = p.first, rr = p.second;
				switch (tmpstr[i]) {
				case 'A':
					tot += (arr[e - 1].query(to[e-1][ll], to[e-1][rr] + 1)).a;
					break;
				case 'G':
					tot += (arr[e - 1].query(to[e - 1][ll], to[e - 1][rr] + 1)).g;
					break;
				case 'C':
					tot += (arr[e - 1].query(to[e - 1][ll], to[e - 1][rr] + 1)).c;
					break;
				case 'T':
					tot += (arr[e - 1].query(to[e - 1][ll], to[e - 1][rr] + 1)).t;
					break;
				}
			}
			cout << tot << endl;
		}
	}
	return 0;
}