#include <bits/stdc++.h>
using namespace std;

struct trie{
	trie* child[26];
	trie() {
		for (int i = 0; i < 26; i++) {
			child[i] = nullptr;
		}
	}
};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s, c; int k, ans = 0;
	cin >> s >> c >> k;
	int n = s.size();
	
	trie *t = new trie();
	
	for (int i = 0; i < n; i++) {
		trie *p = t;
		int cnt = 0;
		
		for (int j = i; j < n; j++) {
			char ch = s[j] - 'a';
			
			if (c[ch] == '0') cnt++;
			if (cnt > k) break;
			
			if (p->child[ch] == nullptr) {
				p->child[ch] = new trie();
				ans++;
			}
			p = p->child[ch];
		}
	}
	cout << ans;
	
	return 0;
}