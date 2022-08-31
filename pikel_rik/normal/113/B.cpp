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
const int N = 2e3 + 5;

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

int lps[N];

void constructLps(const string &pat) {
    int m = pat.length();

    int len = 0, i = 1;
    lps[0] = 0;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len += 1;
            lps[i] = len;
            i += 1;
        }
        else if (len != 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i += 1;
        }
    }
}

int f[26][N], ans;
string s, s1, s2;

void dfs(TrieNode* root, int i, int j) {
    if (i == s1.length() and j == s2.length())
        ans++, j = lps[j-1];
    for (int idx = 0; idx < 26; idx++) {
        if (i != s1.length() and idx == s1[i] - 'a' and root->arr[idx] != nullptr) {
            if (idx == s2[f[idx][j]] - 'a')
                dfs(root->arr[idx], i + 1, f[idx][j] + 1);
            else dfs(root->arr[idx], i + 1, 0);
        }
        else if (i == s1.length() and root->arr[idx] != nullptr) {
            if (idx == s2[f[idx][j]] - 'a')
                dfs(root->arr[idx], i, f[idx][j] + 1);
            else dfs(root->arr[idx], i, 0);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Trie* t = new Trie();

    cin >> s >> s1 >> s2;
    for (int i = 0; i < s.length(); i++) {
        t->insert(s.substr(i, s.length()));
    }

    constructLps(s2);
    for (int j = 0; j < s2.length(); j++) {
        for (int i = 0; i < 26; i++) {
            if (i == s2[j] - 'a' or j == 0)
                f[i][j] = j;
            else f[i][j] = f[i][lps[j-1]];
        }
    }

    dfs(t->root, 0, 0);
    cout << ans << "\n";
    return 0;
}