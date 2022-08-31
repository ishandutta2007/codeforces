#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

int n;
string s;

bool ok = true;

struct node {
    int val;
    node *left, *right;
    explicit node(int x) : val(x), left(nullptr), right(nullptr) {}
};

pair<node*, int> ans[N];
bool visited[N];

void construct(int i) {
    if (i >= n) ok = false;
    if (!ok) return;

    if (s[i] == '0') {
        node *temp = new node(0);
        ans[i] = {temp, 1};
        visited[i] = true;
        return;
    }

    construct(i + 1);
    pair<node*, int> temp1 = ans[i+1];

    construct(i + temp1.second + 1);
    pair<node*, int> temp2 = ans[i + temp1.second + 1];

    node* cur = new node(1);
    cur->left = temp1.first;
    cur->right = temp2.first;

    ans[i] = {cur, temp1.second + temp2.second + 1};
    visited[i] = true;
}

void traverse(node *root) {
    if (root->val == 0) {
        cout << "int";
        return;
    }

    cout << "pair<";
    traverse(root->left);
    cout << ",";
    traverse(root->right);
    cout << ">";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n1;
    string s1;

    cin >> n1;
    getline(cin, s1);
    getline(cin, s1);

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == 'p') {
            s.push_back('1');
            i += 4;
        }
        else if (s1[i] == 'i') {
            s.push_back('0');
            i += 3;
        }
    }

    n = s.length();
    construct(0);

    for (int i = 0; i < n; i++)
        ok &= visited[i];

    if (!ok)
        cout << "Error occurred\n";
    else traverse(ans[0].first);

    return 0;
}