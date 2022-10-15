#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> v;
int x[128][128];
string s;
int a[128];

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n-1; i++) {
        int p = min(v[i].size(), v[i+1].size());
        bool ok = false;
        for (int j = 0; j < p; j++) {
            if (v[i][j] != v[i+1][j]) {
                x[v[i][j]][v[i+1][j]] = 1;
                ok = true;
                break;
            }
        }
        if (!ok && v[i].size() > v[i+1].size()) {
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i = 'a'; i <= 'z'; i++) a[i] = 1;
    while (true) {
        bool mu = false;
        for (int i = 'a'; i <= 'z'; i++) {
            if (!a[i]) continue;
            bool ok = true;
            for (int j = 'a'; j <= 'z'; j++) {
                if (a[j] && x[j][i]) {ok = false; break;}
            }
            if (ok) {
                s += (char)i;
                a[i] = false;
                mu = true;
                break;
            }
        }
        if (!mu) break;
    }
    if (s.size() == 26) cout << s << "\n";
    else cout << "Impossible\n";
}