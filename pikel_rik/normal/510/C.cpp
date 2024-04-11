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

map<char, vector<char>> m;

vector<bool> rstack(26);
vector<bool> visited(26);

bool cycle = false;

int cur = 26;
vector<int> f(26);

void cycle_detect(char i) {
    if (cycle)
        return;

    rstack[i - 'a'] = true;
    visited[i - 'a'] = true;

    for (char &ch : m[i]) {
        if (rstack[ch - 'a']) {
            cycle = true;
            break;
        }
        if (!visited[ch - 'a'])
            cycle_detect(ch);
    }

    rstack[i - 'a'] = false;
}

void dfs (char i) {
    visited[i - 'a'] = true;

    for (char &ch : m[i])
        if (!visited[ch - 'a'])
            dfs(ch);

    f[i - 'a'] = cur--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<bool> has_parent(26);

    for (int i = 1; i < n; i++) {
        int len = min(a[i].length(), a[i-1].length());
        bool flag = false;

        for (int j = 0; j < len; j++) {
            if (a[i][j] != a[i-1][j]) {
                m[a[i - 1][j]].push_back(a[i][j]);
                has_parent[a[i][j] - 'a'] = flag = true;
                break;
            }
        }

        if (!flag and a[i].length() < a[i-1].length()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (char i = 'a'; i <= 'z'; i++) {
        if (!visited[i - 'a'])
            cycle_detect(i);
    }

    if (cycle) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 0; i < 26; i++) visited[i] = false;

    for (char i = 'a'; i <= 'z'; i++) {
        if (!visited[i - 'a'])
            dfs(i);
    }

    for (int i = 1; i <= 26; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            if (f[j - 'a'] == i) cout << j;
        }
    }

    return 0;
}