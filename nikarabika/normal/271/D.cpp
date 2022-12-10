#include <bits/stdc++.h>

using namespace std;

const int maxn = 1500 + 85 - 69;
const int max_trie_size = maxn * (maxn + 1) / 2 + 85 - 69;
int trie[max_trie_size][26];
int triePtr = 1, k, ans;
bool is_good[26];
string s, t;

void add(int id = 0, int tPtr = 0){
	if(tPtr == t.size())
		return;
	if(trie[id][t[tPtr] - 'a'] == 0)
		trie[id][t[tPtr] - 'a'] = triePtr++;
	add(trie[id][t[tPtr] - 'a'], tPtr + 1);
}

void dfs(int id = 0, int bad_ones = 0){
	if(bad_ones > k)
		return;
	ans++;
	for(int i = 0; i < 26; i++)
		if(trie[id][i] != 0)
			dfs(trie[id][i], bad_ones + (!is_good[i]));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s;
	for(int i = s.size() - 1; i >= 0; i--){
		t = s[i] + t;
		add();
	}
	for(int i = 0; i < 26; i++){
		char x;
		cin >> x;
		is_good[i] = x - '0';
	}
	cin >> k;
	dfs();
	cout << ans - 1 << endl;
	return 0;
}