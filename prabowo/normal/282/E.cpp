#include <cstdio>
#include <algorithm>

typedef long long LL;

const int N = 100000;

LL a[N];

struct Trie {
	Trie *child[2];
	
	Trie () {
		child[0] = child[1] = 0;		
	}
	
	void insert (LL x, int depth) {
		if (depth == -1) return;
		
		if (!child[x >> depth & 1]) child[x >> depth & 1] = new Trie();
		child[x >> depth & 1] -> insert (x, depth - 1);
		return;
	}
	
	LL maks (LL x, int depth) {
		if (depth == -1) return 0;
		
		if (x >> depth & 1) {
			if (child[0]) return (1LL << depth) + child[0] -> maks (x, depth - 1);
			return child[1] -> maks (x, depth - 1);
		}
		
		if (child[1]) return (1LL << depth) + child[1] -> maks (x, depth - 1);
		return child[0] -> maks (x, depth - 1);
	}
	
} *root = 0;

int main () {
	int n;
	scanf ("%d", &n);
	for (int i=0; i<n; i++) scanf ("%I64d", a + i);
	
	LL prefix = 0;
	LL suffix = 0;
	for (int i=0; i<n; i++) prefix ^= a[i];
	
	root = new Trie();
	root -> insert (0, 40);
	
	LL maks = prefix;
	for (int i=n; i;) {
		root -> insert (suffix ^= a[--i], 40);
		maks = std :: max (maks, root -> maks (prefix ^= a[i], 40));
	}
	
	printf ("%I64d\n", maks);
	return 0;
}