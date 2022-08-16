#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1500 + 1;

class TrieNode {
public:
    TrieNode* arr[26];
    bool isEnd;
};

TrieNode* newNode () {
    TrieNode* node = new TrieNode;
    for (auto &i : node->arr) i = nullptr;
    node->isEnd = false;
    return node;
}

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = newNode();
    }

    void insert (string s) const {
        int idx = 0;
        int n = s.length();

        TrieNode *curNode = root;
        while (idx < n) {
            if (!curNode->arr[s[idx] - 'a'])
                curNode->arr[s[idx] - 'a'] = newNode();
            curNode = curNode->arr[s[idx] - 'a'];
            idx += 1;
        }
        curNode->isEnd = true;
    }

    bool search(string s) const {
        int idx = 0;
        int n = s.length();

        TrieNode *curNode = root;
        while (idx < n) {
            if (!curNode->arr[s[idx] - 'a'])
                return false;
            curNode = curNode->arr[s[idx] - 'a'];
            idx += 1;
        }
        return (curNode != nullptr and curNode->isEnd);
    }
};

string bad;
int k;
ll ans = 0;

void dfs (TrieNode* x, int c = 0) {
    ans += 1;
    for (int i = 0; i < 26; i++) {
        if (!x->arr[i]) continue;
        if (bad[i] == '0' and c < k) dfs(x->arr[i], c + 1);
        else if (bad[i] == '1') dfs(x->arr[i], c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();
    cin >> bad;

    cin >> k;

    Trie* t = new Trie();

    for (int i = 0; i < n; i++) {
        t->insert(s);
        s.erase(s.begin());
    }

    dfs(t->root);
    cout << ans - 1;
    return 0;
}