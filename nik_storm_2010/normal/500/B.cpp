#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e3;

vector <int> base, value;
int p[N], n;
string s[N];
bool used[N];

void dfs(int x) {
    used[x] = true;
    base.push_back(x);
    value.push_back(p[x]);
    for (int i = 0; i < n; i++)
        if (s[x][i] == '1' && !used[i])
            dfs(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;
        base.clear();
        value.clear();
        dfs(i);
        sort(base.begin(), base.end());
        sort(value.begin(), value.end());
        for (int j = 0; j < base.size(); j++)
            p[base[j]] = value[j];
    }
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    return 0;
}