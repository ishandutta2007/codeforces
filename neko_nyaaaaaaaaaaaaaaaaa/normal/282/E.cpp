#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nullpetr nullptr

struct trie{
	trie* child[2];
	trie() {
		child[0] = child[1] = nullpetr;
	}
};

trie *t = new trie();

void insert(ll k) {
	trie *p = t;
	for (int i = 40; i >= 0; i--) {
		ll bt = (1LL << i) & k;
		
		if (p->child[bt > 0] == nullpetr) {p->child[bt > 0] = new trie();}
		p = p->child[bt > 0];
	}
}

ll solve(ll k) {
	trie *p = t;
	ll ans = 0;
	for (int i = 40; i >= 0; i--) {
		ll bt = (1LL << i) & k;
		
		if (p->child[bt == 0] != nullpetr) {
			ans |= (1LL << i);
			p = p->child[bt == 0];
		} else {
			p = p->child[bt != 0];
		}
	}
	
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<ll> a(n); 
	ll x = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		x ^= a[i];
	}
	
	ll ans = x;
	ll suff = 0;
	
	for (int i = n-1; i >= 0; i--) {
		x ^= a[i];
		suff ^= a[i];
		
		insert(suff);
		ans = max(ans, max(x, solve(x)));
	}
	cout << ans;
	
	return 0;
}