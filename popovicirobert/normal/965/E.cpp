#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

struct Trie {
    Trie *son[26];
    bool ok;
    Trie() {
        memset(son, 0, sizeof(son));
        ok = 0;
    }
};

Trie *root = new Trie;

string str;

void add(Trie *nod, int p, int n) {
    if(p == n) {
        nod -> ok = 1;
    }
    else {
        char ch = str[p] - 'a';
        if(nod -> son[ch] == NULL)
            nod -> son[ch] = new Trie;
        add(nod -> son[ch], p + 1, n);
    }
}

inline multiset <int> join(multiset <int> a, multiset <int> b) {
    if(a.size() > b.size())
        swap(a, b);
    for(auto it : a) {
        b.insert(it);
    }
    return b;
}

multiset <int> solve(Trie *nod, int lvl) {
    multiset <int> mst;
    multiset <int> :: iterator it;
    for(int i = 0; i < 26; i++) {
        if(nod -> son[i] != NULL) {
            mst = join(mst, solve(nod -> son[i], lvl + 1));
        }
    }
    if(nod -> ok == 1)
        mst.insert(lvl);
    else if(mst.size() > 0 && nod != root) {
        it = mst.end();
        it--;
        mst.erase(it);
        mst.insert(lvl);
    }
    return mst;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> str;
        add(root, 0, str.size());
    }
    multiset <int> mst = solve(root, 0);
    int ans = 0;
    for(auto it : mst) {
        ans += it;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}