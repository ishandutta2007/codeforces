#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct triearr {
	ll words = 0, ab, totalLen, trieSize = 1;
	vector<map<ll, int>> trie;
	vector<ll> info;
	int firstLetter;
	triearr(ll totalLen) {
		this->totalLen = totalLen;
		trie.resize(totalLen);
		info.assign(totalLen, -1);
	}
	ll insert(const vector<ll>& str) {
		ll len = str.size(), cur = 0;
		foru(i, 0, len) {
			if (trie[cur].find(str[i]) == trie[cur].end())
				trie[cur][str[i]] = trieSize++;
			cur = trie[cur][str[i]];
		}
		return info[cur] = words++;
	}
};

const int sz = 20;
int n;
vector<ll> v[sz];
ll bstback[sz];
vector<int> bstbacks[sz];
triearr* tr;
vector<int> bstc;

pair<ll, vector<int>> getBest(int idx, int cur) {
	if (idx == n) {
		return { -1e18, vector<int>{} };
	}
	ll bst = -1e18;
	vector<int> bstv = {};
	ford(i, v[idx].size() - 1, 0) {
		if (tr->trie[cur].find(i) != tr->trie[cur].end()) {
			pair<ll, vector<int>> tmp = getBest(idx + 1, tr->trie[cur][i]);
			if (tmp.ff + v[idx][i] > bst) {
				bst = tmp.ff + v[idx][i];
				bstv = tmp.ss;
				bstv.push_back(i);
			}
		}
		else {
			if (bst < v[idx][i] + bstback[idx + 1]) {
				bst = v[idx][i] + bstback[idx + 1];
				bstv = bstbacks[idx + 1];
				bstv.push_back(i);
			}
			break;
		}
	}
	return { bst,bstv };
}

int main() {
	fast;
	cin >> n;
	foru(i, 0, n) {
		int k;
		cin >> k;
		foru(j, 0, k) {
			int tmp; cin >> tmp;
			v[i].push_back(tmp);
		}
	}
	int m;
	cin >> m;
	tr = new triearr(2 * (m + 1) * n);
	tr->insert(vector<ll>{-1});
	foru(i, 0, m) {
		vector<ll> v(n);
		foru(j, 0, n) {
			cin >> v[j]; v[j]--;
		}
		tr->insert(v);
	}
	ford(i, n - 1, 0) {
		bstback[i] = bstback[i + 1] + v[i].back();
		bstbacks[i] = bstbacks[i + 1];
		bstbacks[i].push_back(v[i].size() - 1);
	}
	pair<ll, vector<int>> bst = getBest(0, 0);
	ford(i, n - 1, 0)cout << bst.ss[i] + 1 << ' ';
	return 0;
}