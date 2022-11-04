#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 3e5;

int a[MAXN + 1];

struct Trie {
    Trie *son[2];
    int sz;
    Trie() {
        memset(son, 0, sizeof(son));
        sz = 0;
    }
};

Trie *root = new Trie;

void add(Trie *nod, char bit, int val) {
    if(bit >= 0) {
        bool r = ((val & (1 << bit)) > 0);
        if(nod -> son[r] == NULL)
            nod -> son[r] = new Trie;
        add(nod -> son[r], bit - 1, val);
    }
    nod -> sz++;
}

int solve(Trie *nod, char bit, int val) {
    nod -> sz--;
    if(bit >= 0) {
        bool r = ((val & (1 << bit)) > 0);
        if(nod -> son[r] != NULL && nod -> son[r] -> sz > 0) {
            return solve(nod -> son[r], bit - 1, val);
        }
        else {
            return solve(nod -> son[1 - r], bit - 1, val) + (1 << bit);
        }
    }
    return 0;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> x;
        add(root, 29, x);
    }
    for(i = 1; i <= n; i++) {
        cout << solve(root, 29, a[i]) << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}