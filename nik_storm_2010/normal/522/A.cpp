#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;
const int N = 1000;

set <char> lower;
map <string, int> ps;
vector <int> edges[N];
int ans;

void transform(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (lower.find(s[i]) != lower.end()) {
            s[i] = s[i] - 'a' + 'A';
        }
    }
}

void dfs(int x, int dp) {
    ans = max(ans, dp);
    for (size_t i = 0; i < edges[x].size(); i++) {
        dfs(edges[x][i], dp + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    for (char i = 'a'; i <= 'z'; i++) {
        lower.insert(i);
    }
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        string s1, rubbish, s2;
        cin >> s1 >> rubbish >> s2;
        transform(s1);
        transform(s2);
        if (ps[s1] == 0) {
            ps[s1] = ++cnt;
        }
        if (ps[s2] == 0) {
            ps[s2] = ++cnt;
        }
        edges[ps[s1]].push_back(ps[s2]);
    }
    ans = 0;
    for (int i = 1; i <= cnt; i++) {
        dfs(i, 1);
    }
    cout << ans << "\n";
    return 0;
}