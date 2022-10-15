#include<bits/stdc++.h>
 
using namespace std;
 
 
#define MOD 1e9+7
#define INF 1e18
#define END "\n"
#define ll long long int
#define pb push_back
#define loop(i, a, b) for(register int i = (a); i < (b); i++)
 
#define N 202020
string alpha = "abcdefghijklmnopqrstuvwxyz";
const int mod = MOD;
 
//
 
const int ALPHABET_SIZE = 2; 
struct TrieNode { 
	struct TrieNode* children[ALPHABET_SIZE]; 
	bool isEndOfWord; 
}; 
 
struct TrieNode* getNode(void) 
{ 
	struct TrieNode* pNode = new TrieNode; 
	pNode->isEndOfWord = false; 
	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 
	return pNode; 
} 
 
void insert(struct TrieNode* root, string key) 
{ 
	struct TrieNode* pCrawl = root; 
 
	for (int i = 0; i < key.length(); i++) { 
		int index = key[i] - '0'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 
 
		pCrawl = pCrawl->children[index]; 
	} 
	pCrawl->isEndOfWord = true; 
} 
bool search(struct TrieNode* root, string key) 
{ 
	struct TrieNode* pCrawl = root; 
 
	for (int i = 0; i < key.length(); i++) { 
		int index = key[i] - '0'; 
		if (!pCrawl->children[index]) 
			return false; 
 
		pCrawl = pCrawl->children[index]; 
	} 
 
	return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
 
bool isEmpty(TrieNode* root) 
{ 
	for (int i = 0; i < ALPHABET_SIZE; i++) 
		if (root->children[i]) 
			return false; 
	return true; 
} 
 
TrieNode* remove(TrieNode* root, string key, int depth = 0) 
{  
	if (!root) 
		return NULL;  
	if (depth == key.size()) { 
 
		if (root->isEndOfWord) 
			root->isEndOfWord = false;  
		if (isEmpty(root)) { 
			delete (root); 
			root = NULL; 
		} 
		return root; 
	} 
	int index = key[depth] - '0'; 
	root->children[index] = 
		remove(root->children[index], key, depth + 1); 
 
	if (isEmpty(root) && root->isEndOfWord == false) { 
		delete (root); 
		root = NULL; 
	} 
 
	return root; 
} 
 
string bin32(int n){
	return bitset<32>(n).to_string();
}
 
int xr(TrieNode* root, string s){
	struct TrieNode* pCrawl = root;
 
	vector<int> res(32);
 
	loop(i, 0, s.length()){
		int index = s[i] - '0';
 
		if(index == 0){
			if (!pCrawl->children[1]){ 
				res[i] = 0;
				pCrawl = pCrawl->children[0];
			}else{
				res[i] = 1;
				pCrawl = pCrawl->children[1];
			} 			
		}
		if(index == 1){
			if (!pCrawl->children[0]){ 
				res[i] = 0;
				pCrawl = pCrawl->children[1];
			}else{
				res[i] = 1;
				pCrawl = pCrawl->children[0];
			} 	
		}
	}
 
	int val = 0;
	loop(i, 0, 32){
		int index = 31-i;
		val += (res[index]*pow(2,i));
	}
	return val;
 
}
 
 
//
 
int main(){
 
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//
	//fin&fout
	#ifndef ONLINE_JUDGE
	freopen("fin.txt", "r", stdin);
	freopen("fout.txt", "w", stdout);
	#endif	//
 
	int n; cin >> n;
	unordered_map<int, int> cnt;
	struct TrieNode* root = getNode();
	insert(root, bin32(0));
 
	loop(i, 0, n){
		char q; int x;
		cin >> q >> x;
		if(q == '+'){
			cnt[x] += 1;
			if (cnt[x] == 1){
				insert(root, bin32(x));
			}
		}
		if(q == '-'){
			cnt[x] -= 1;
			if(cnt[x] == 0){
				remove(root, bin32(x));
			}
		}
		if(q == '?'){
			int res = xr(root, bin32(x));
			cout << res << END;
		}
 
	}
 
 
	return 0;
 
}