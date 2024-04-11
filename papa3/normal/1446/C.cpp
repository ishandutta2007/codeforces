#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

template<class C> void mini(C &a5, C b5) { a5 = min(a5, b5); }
template<class C> void maxi(C &a5, C b5) { a5 = max(a5, b5); }

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

//#define int long long
#define double long double

//const int INF = 1e18;
const int mod = 1e9 + 7;

struct Node {
	Node *syn[2];
	int gl;
	int ile;
	
	Node(int _gl) {
		gl = _gl;
		syn[0] = syn[1] = nullptr;
		ile = 0;
	}
	
	void zwal() {
		if (syn[0] == nullptr) {
			syn[0] = new Node(gl - 1);
			syn[1] = new Node(gl - 1);
		}
	}
	
	void add(int x) {
		ile++;
		if (gl == -1) return;
		zwal();
		if (x & (1 << gl))
			syn[1]->add(x);
		else
			syn[0]->add(x);
	}
	
	int algo() {
		if (syn[0] == nullptr) return 0;
		int t[2];
		t[0] = syn[0]->algo();
		t[1] = syn[1]->algo();
		
		return min(
			t[0] + max(syn[1]->ile - 1, 0),
			t[1] + max(syn[0]->ile - 1, 0)
		);
	}
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    Node root(30);
    
    int n;
    cin >> n;
    for (int a, i = 0; i < n; i++) {
		cin >> a;
		root.add(a);
	}
	
	cout << root.algo();
	//cout << (1 << 30);
    
    return 0;
}/*

*/