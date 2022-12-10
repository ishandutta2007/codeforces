#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 5e3 + 2;
int seg[maxn * maxn / 2];
vector<pie> sorted;
vector<int> TrieVector[maxn];
int Trie[maxn * maxn / 2][2], TriePtr = 1;
int address[maxn * maxn / 2], trie_input_start;
bool ispal[maxn * maxn / 2], check[maxn * maxn / 2];
string s;
int k;

int place(int i, int j){
	int x = s.size() * i;
	x -= (i * (i - 1)) / 2;
	x += j - i;
	return x;
}

void add(int sPtr, int id = 0){
	if(sPtr == s.size()){
		seg[id] = trie_input_start;
		return;
	}
	if(Trie[id][s[sPtr] - 'a'] == 0)
		Trie[id][s[sPtr] - 'a'] = TriePtr++;
	add(sPtr + 1, Trie[id][s[sPtr] - 'a']);
}

void dfs(int id, int h = -1, int TrieVectorPtr = 0){
	if(Trie[id][1])
		dfs(Trie[id][1], h + 1, TrieVectorPtr);
	if(Trie[id][0])
		dfs(Trie[id][0], h + 1, TrieVectorPtr + 1);
	for(int i = 0; i < TrieVector[TrieVectorPtr + 1].size(); i++)
		TrieVector[TrieVectorPtr].PB(TrieVector[TrieVectorPtr + 1][i]);
	if(seg[id] != -1)
		TrieVector[TrieVectorPtr].PB(seg[id]);
	TrieVector[TrieVectorPtr + 1].clear();
	if(h != -1){
		for(int i = 0; i < TrieVector[TrieVectorPtr].size(); i++){
			int x = TrieVector[TrieVectorPtr][i];
			address[place(x, x + h)] = sorted.size();
			sorted.PB(MP(x, x + h));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	sorted.reserve(maxn * maxn / 2);
	memset(seg, -1, sizeof seg);
	cin >> s >> k;
	for(int i = 0; i < s.size(); i++){
		trie_input_start = i;
		add(i);
	}
	dfs(0);
	for(int i = 0; i < s.size(); i++)
		ispal[place(i, i)] = true;
	for(int i = 0; i + 1 < s.size(); i++)
		ispal[place(i, i + 1)] = (s[i] == s[i + 1]);
	for(int i = 0; i + 2 < s.size(); i++)
		ispal[place(i, i + 2)] = (s[i] == s[i + 2]);
	for(int i = 0; i + 3 < s.size(); i++)
		ispal[place(i, i + 3)] = (s[i] == s[i + 3]);
	for(int l = 5; l <= s.size(); l++)
		for(int i = 0; i + l <= s.size(); i++)
			ispal[place(i, i + l - 1)] = ((s[i] == s[i + l - 1]) and ispal[place(i + 2, i + l - 3)]);
	for(int i = 0; i < s.size(); i++)
		for(int j = i; j < s.size(); j++)
			if(ispal[place(i, j)])
				check[address[place(i, j)]] = true;
	for(int i = sorted.size() - 1; i >= 0; i--){
		k -= (check[i]) ? 1 : 0;
		if(!k){
			cout << s.substr(sorted[i].L, sorted[i].R - sorted[i].L + 1) << endl;
			return 0;
		}
	}
	return 0;
}