#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
	bool leaf = false;
	ll val = 0;
	ll next[2] = {-1, -1};
};
vector<node> trie(1);
void add(ll x) {
	ll v = 0;
	bitset<60> bt(x);
	for (int k = 59; k >= 0; k--) {
		int i = bt[k];
		if (trie[v].next[i] == -1) {
			trie[v].next[i] = trie.size();
			trie.emplace_back();
		}
		v = trie[v].next[i];
	}
	trie[v].leaf = true;
}
ll find(ll x) {
	ll v = 0;
	ll offset = 0;
	bitset<60> bt(x);
	for (int k = 59; k >= 0; k-- ) {
		int i = bt[k];
		if (trie[v].next[i] == -1) {
			v = trie[v].next[i ^ 1];
			offset = (offset << 1ll) + (i ^ 1);
		} else {
			v = trie[v].next[i];
			offset = (offset << 1ll) + i;
		}
	}
	return offset;
}
//cur ^ all ^ find((-cur^all-1)
int main() {
	ll N, ans = 0, all = 0, cur = 0, A[100005];
	memset(A, 0, sizeof(A));
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		all ^= A[i];
	}
	add(0);
 
    ll opt = 1ll << 50ll; opt--;
	for (int i = 0; i <= N; i++) {
		cur ^= A[i];
		add(cur);
		ll c = all ^ cur ^ find(all ^ cur ^ opt);
		//cout << c << endl;
		ans = max(ans, c);
		add(cur);
	}
	cout << ans << "\n";
	return 0;
}