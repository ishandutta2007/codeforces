#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int Mod = 1000000007;

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137
,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293}; // (size = 62)

int modPow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 0) {a = (1LL * a * a) % Mod; b /= 2;}
        else {res = (1LL * res * a) % Mod; b -= 1;}
    }
    return res;
}

struct ProTree {
	vector<int> Tree, Lazy;
	ProTree() {}
	ProTree(int n) {Tree.resize(n*4, 1); Lazy.resize(n*4, 1);}
	
	void Propagate(int node, int st, int en) {
		if (Lazy[node] == 1) return;
		Tree[node] = (1LL * Tree[node] * modPow(Lazy[node], (en - st + 1))) % Mod;
		if (st != en) {
			Lazy[node*2+1] = (1LL * Lazy[node*2+1] * Lazy[node]) % Mod;
			Lazy[node*2+2] = (1LL * Lazy[node*2+2] * Lazy[node]) % Mod;
		}
		Lazy[node] = 1;
	}
	
	void Multiply(int node, int st, int en, int L, int R, int val) {
		Propagate(node, st, en);
		if (st > en || en < L || R < st) return;
		if (L <= st && en <= R) {
			Lazy[node] = (1LL * Lazy[node] * val) % Mod;
			Propagate(node, st, en); return;
		}
		Multiply(node*2+1, st, (st+en)/2+0, L, R, val);
		Multiply(node*2+2, (st+en)/2+1, en, L, R, val);
		Tree[node] = (1LL * Tree[node*2+1] * Tree[node*2+2]) % Mod;
	}
	
	int Product(int node, int st, int en, int L, int R) {
		Propagate(node, st, en);
		if (st > en || en < L || R < st) return 1;
		if (L <= st && en <= R) return Tree[node];
		int p1 = Product(node*2+1, st, (st+en)/2+0, L, R);
		int p2 = Product(node*2+2, (st+en)/2+1, en, L, R);
		return ((1LL * p1 * p2) % Mod);
	}
};

struct OrTree {
	vector<long long> Tree, Lazy;
	OrTree() {}
	OrTree(int n) {Tree.resize(n*4); Lazy.resize(n*4);}
	
	void Propagate(int node, int st, int en) {
		if (Lazy[node] == 0) return;
		Tree[node] |= Lazy[node];
		if (st != en) {
			Lazy[node*2+1] |= Lazy[node];
			Lazy[node*2+2] |= Lazy[node];
		}
		Lazy[node] = 0;
	}
	
	void Update(int node, int st, int en, int L, int R, long long val) {
		Propagate(node, st, en);
		if (st > en || en < L || R < st) return;
		if (L <= st && en <= R) {
			Lazy[node] |= val;
			Propagate(node, st, en); return;
		}
		Update(node*2+1, st, (st+en)/2+0, L, R, val);
		Update(node*2+2, (st+en)/2+1, en, L, R, val);
		Tree[node] = (Tree[node*2+1] | Tree[node*2+2]);
	}
	
	long long Or(int node, int st, int en, int L, int R) {
		Propagate(node, st, en);
		if (st > en || en < L || R < st) return 0;
		if (L <= st && en <= R) return Tree[node];
		long long p1 = Or(node*2+1, st, (st+en)/2+0, L, R);
		long long p2 = Or(node*2+2, (st+en)/2+1, en, L, R);
		return (p1 | p2);
	}
};

int N, Q, l, r, x; string cmd;
vector<int> invPrime(62);
vector<int> A; ProTree PrTree; OrTree OSTree;
vector<long long> Mask(301, 0);

void PreprocessMask() {
	for (int z=1; z<=300; z++) {
		for (int i=0; i<62; i++) {
			if (z % prime[i] != 0) continue;
			Mask[z] |= (1LL << i);
		}
	}
}

void Input() {
    for (int i=0; i<62; i++) invPrime[i] = modPow(prime[i], Mod-2); PreprocessMask();
	cin >> N >> Q; A.resize(N); PrTree = ProTree(N); OSTree = OrTree(N);
	for (int i=0; i<N; i++) {
		cin >> A[i];
		PrTree.Multiply(0, 0, N-1, i, i, A[i]);
		OSTree.Update(0, 0, N-1, i, i, Mask[A[i]]);
	}
}

void Solve() {
	while (Q--) {
		cin >> cmd >> l >> r; l--; r--;
		if (cmd == "MULTIPLY") {
			cin >> x;
			PrTree.Multiply(0, 0, N-1, l, r, x);
			OSTree.Update(0, 0, N-1, l, r, Mask[x]);
		}
		else if (cmd == "TOTIENT") {
			int res = PrTree.Product(0, 0, N-1, l, r);
			long long SegMask = OSTree.Or(0, 0, N-1, l, r);
			for (int i=0; i<62; i++) {
			    if ((SegMask & (1LL << i)) == 0) continue;
			    res = (1LL * res * (prime[i] - 1)) % Mod;
			    res = (1LL * res * invPrime[i]) % Mod;
			}
			cout << res << endl;
		}
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}