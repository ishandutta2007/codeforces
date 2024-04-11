#include <cstdio>

int n, k;
struct Trie {
	int size;
	Trie *child[2];
	
	Trie () {
		size = 0;
		child[0] = child[1] = 0;
	}
	
	int getSize (Trie *node) {
		if (node) return node->size;
		return 0;
	}
	
	void add (int val, int h) {
		if (h < 0) {
			size++;
			return;
		}
		
		if (child[val >> h & 1]); else child[val >> h & 1] = new Trie();
		child[val >> h & 1] -> add (val, h - 1);
		
		size = getSize (child[0]) + getSize (child[1]);
		// printf ("%d\n", size);
	}
	
	int count (int val, int Xor, int h) {
		if (h < 0) return size * (val >= k);
		if (val + (1 << h) >= k) return getSize(child[1 - (Xor >> h & 1)]) + (child[Xor >> h & 1] ? child[Xor >> h & 1]->count(val, Xor, h-1) : 0);
		return (child[1 - (Xor >> h & 1)] ? child[1 - (Xor >> h & 1)]->count(val + (1 << h), Xor, h-1) : 0);
	}
} *root;

int main () {
	scanf ("%d %d", &n, &k);
	int a;
	long long ans = 0;
	
	root = new Trie(); int prefix = 0;
	root->add (0, 30);
	
	for (int i=0; i<n; i++) {
		scanf ("%d", &a);
		prefix ^= a;
		ans += root->count(0, prefix, 30);
		root->add(prefix, 30);
		// printf ("%I64d\n", ans);
	}
	
	printf ("%I64d\n", ans);
	return 0;
}