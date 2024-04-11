#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MAXDIG=40;
struct Node {
	int cnt=0;
	int nxt[2];
	Node() {nxt[0]=nxt[1]=-1;}
};
vector<Node> trie(1);
void add(ll x) {
	int cur=0;
	++trie[0].cnt;
	for (int i=MAXDIG; ~i; --i) {
		int c=(x>>i)&1;
		if (trie[cur].nxt[c]==-1) {
			trie[cur].nxt[c]=trie.size();
			trie.emplace_back();
		}
		cur=trie[cur].nxt[c];
		++trie[cur].cnt;
	}
}

void remove(ll x) {
	int cur=0;
	--trie[0].cnt;
	for (int i=MAXDIG; ~i; --i) {
		int c=(x>>i)&1;
		assert(trie[cur].nxt[c]!=-1);
		cur=trie[cur].nxt[c];
		--trie[cur].cnt;
	}
}

ll search(ll x) { //best xor in trie 
	int cur=0;
	ll res=0;
	for (int i=MAXDIG; ~i; --i) {
		int c=(x>>i)&1;
		if (trie[cur].nxt[c^1]!=-1&&trie[trie[cur].nxt[c^1]].cnt>0) {
			res+=(1ll<<i);
			cur=trie[cur].nxt[c^1];
		}
		else {
			cur=trie[cur].nxt[c];
		}
	}
	return res;
}

int n;
ll a[100000], ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	add(0);
	ll pre=0, suf=0;
	for (int i=n-1; ~i; --i) {
		suf^=a[i];
		add(suf);
	}
	ans=search(0);
	for (int i=0; i<n; ++i) {
		remove(suf);
		suf^=a[i];
		pre^=a[i];
		ans=max(ans, search(pre));
	}
	cout << ans;
	return 0;
}