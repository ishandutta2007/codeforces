#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;
vector<string> res;

struct Node {
    bool has[2];
    int ter;
    Node *child[2];
    Node() {
        has[0] = has[1] = 0;
        child[0] = child[1] = NULL;
        ter = -1;
    }

    void dfs(string now) {
        if (has[0] == 0) return;
        if (has[1] == 0) {
            res.push_back(now);
            return;
        }
        if (child[0]) child[0]->dfs(now + '0');
        if (child[1]) child[1]->dfs(now + '1');
    }
};
Node *root;

bool add(string s, int f) {
    Node *now = root;
    for (char u : s) {
        if (now->ter == f) return 1;
        if (now->ter == (f ^ 1)) {
            return 0;
        }
        now->has[f] |= 1;
        int id = u - '0';
        if (now->child[id] == NULL) now->child[id] = new Node();
        now = now->child[id];
    }
    if (now->has[f ^ 1]) return 0;
    now->has[f] = 1;
    now->ter = f;

    return 1;
}

string getVal(string s) {
    s = s.substr(1);
    s += '.';
    vector<int> foo;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') cur = cur * 10 + s[i] - '0';
        else {
            foo.push_back(cur);
            cur = 0;
        }
    }
    int range = foo.back();
    string res = "";
    for (int i = 0; i + 1 < foo.size(); i++) {
        for (int j = 7; j >= 0; j--) {
            res += (char)('0' + ((foo[i] >> j) & 1));
        }   
    }
    return res.substr(0, range);
}

string toString(int u) {
    string res = "";
    if (u == 0) return "0";
    while (u) {
        res += (char)(u % 10 + '0');
        u /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

void output(string u) {
    int foo = u.size();
    for (int i = foo + 1; i <= 32; i++) u += "0";
    vector<int> ans;
    int cnt = 0;
    for (int i = 1; i <= 4; i++) {
        int cur = 0;
        for (int j = 0; j < 8; j++) {
            cur = (cur << 1) | (u[cnt++] == '1');
        }
        ans.push_back(cur);
    }
    string res = "";
    for (int v : ans) {
        res += toString(v) + '.';
    }
    res.pop_back();
    res += '/';
    res += toString(foo);
    cout << res << '\n';
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    root = new Node();
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s.find('/') == string::npos) {
            s += "/32";
        }
        string u = getVal(s);
        if(!add(u, s[0] == '+')) {
            cout << -1 << endl;
            return 0;
        }
    }
    root->dfs("");
    cout << res.size() << endl;
    for (string u : res) {
        output(u);
    }
    return 0;
}