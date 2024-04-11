#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, k;
string a[N];

struct TrieNode {
    TrieNode* arr[26];
    bool isEnd;
    TrieNode() : arr{}, isEnd() {}
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert (const string& s) const {
        TrieNode *curNode = root;
        for (char ch : s) {
            if (!curNode->arr[ch - 'a'])
                curNode->arr[ch - 'a'] = new TrieNode();
            curNode = curNode->arr[ch - 'a'];
        }
        curNode->isEnd = true;
    }

    bool search(const string& s) const {
        TrieNode *curNode = root;
        for (char ch : s) {
            if (!curNode->arr[ch - 'a'])
                return false;
            curNode = curNode->arr[ch - 'a'];
        }
        return (curNode != nullptr and curNode->isEnd);
    }
};

bool dfs1(TrieNode* root) {
    bool ans = false;
    for (TrieNode* i : root->arr) {
        if (i) ans |= !dfs1(i);
    }
    return ans;
}

bool dfs2(TrieNode* root) {
    bool ans = false, leaf = true;
    for (TrieNode* i : root->arr) {
        if (i) ans |= !dfs2(i), leaf = false;
    }
    if (leaf)
        return true;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    Trie* t = new Trie();

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t->insert(a[i]);
    }

    bool ans1 = dfs1(t->root), ans2 = dfs2(t->root);
//    cout << ans1 << " " << ans2 << "\n";

    if (!ans1) {
        cout << "Second\n";
        return 0;
    }

    if (ans2) {
        cout << "First\n";
        return 0;
    }

    if (k % 2) cout << "First\n";
    else cout << "Second\n";
    return 0;
}