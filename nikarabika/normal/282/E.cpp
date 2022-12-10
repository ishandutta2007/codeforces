//In the name of "God"
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 1e5 + 85 - 69, maxl = 48;
const string empty;
LL a[maxn], output[maxl];
string trie_input;
int trie[(int)5e6 + 85 - 69], child[(int)5e6 + 85 - 69][2], triePtr = 1;
int n;
LL ans;

string stringof(LL x){
	string ret = empty;
	for(int i = 0; i < maxl; i++)
		ret += char(0);
	for(int i = 0; i < maxl; i++)
		ret[maxl - i - 1] = bool(x & (1LL << i));
	return ret;
}

void add(int id = 0, int inputPtr = 0){
	trie[id]++;
	if(inputPtr == trie_input.size())
		return;
	if(child[id][trie_input[inputPtr]] == 0)
		child[id][trie_input[inputPtr]] = triePtr++;
	add(child[id][trie_input[inputPtr]], inputPtr + 1);
}

void remove(int id = 0, int inputPtr = 0){
	trie[id]--;
	if(inputPtr == trie_input.size())
		return;
	remove(child[id][trie_input[inputPtr]], inputPtr + 1);
	if(trie[child[id][trie_input[inputPtr]]] == 0)
		child[id][trie_input[inputPtr]] = 0;
}

void get(int id = 0, int inputPtr = 0){
	if(inputPtr == trie_input.size())
		return;
	int x = trie_input[inputPtr];
	if(child[id][1 - x]){
		output[inputPtr] = 1 - x;
		get(child[id][1 - x], inputPtr + 1);
		return;
	}
	output[inputPtr] = x;
	get(child[id][x], inputPtr + 1);
}

void make(){
	LL y = 0;
	for(int i = n + 1; i >= 0; i--){
		y ^= a[i];
		trie_input = stringof(y);
		add();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	/*while(cin >> n){
		string t = stringof(n);
		for(int i = 0; i < t.size(); i++)
			cout << t[i] + 0;
		cout << endl;
		trie_input = t;
		add();
		cout << triePtr << endl;
	}*/
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	make();
	LL x = 0, y = 0;
	for(int i = n; i > 0; i--)
		y ^= a[i];
	for(int i = 0; i <= n; i++){
		x ^= a[i];
		trie_input = stringof(y);
		remove();
		y ^= a[i];
		trie_input = stringof(x);
		get();
		LL XOR = 0;
		for(int i = 0; i < maxl; i++)
			XOR = XOR * 2 + (trie_input[i] != output[i]);
		ans = max(ans, XOR);
	}
	cout << ans << endl;
	return 0;
}

/*
   age ye rooz beri safar
   beri ze pisham bikhabar
   be TOKHM-e CHAPAM
   aslan che behtar ke gooreto gom karD :|
*/