#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;

int n, q;

map<string, string> exam;
map<string, int> cnt;
set<string> app;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        app.clear();
        for (int j = 0; j < s.length(); j++)
            for (int k = j; k < s.length(); k++) {
                string cur;
                for (int l = j; l <= k; l++) cur.push_back(s[l]);
                if (app.count(cur)) continue;
                app.insert(cur);
                if (cnt.count(cur)) cnt[cur]++;
                else {
                    cnt[cur] = 1;
                    exam[cur] = s;
                }
            }
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        if (cnt.count(s)) {
            cout << cnt[s] << ' ' << exam[s] << '\n';
        } else {
            cout << 0 << ' ' << "-\n";
        }
    }
    return 0;
}