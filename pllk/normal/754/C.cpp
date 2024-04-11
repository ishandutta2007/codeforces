#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
string s[111];
int m;
string r[111];
set<string> p[111];

int ok(string a, string b) {
    for (int i = 0; i+b.size()-1 < a.size(); i++) {
        int z = 1;
        for (int j = 0; j < b.size(); j++) {
            if (a[i+j] != b[j]) z = 0;
        }
        if (!z) continue;
        if (i > 0 && a[i-1] != ' ' && a[i-1] != ':' && a[i-1] != '.' && a[i-1] != ',' && a[i-1] != '!' && a[i-1] != '?') continue;
        int j = b.size();
        if (i+j < a.size() && a[i+j] != ' ' && a[i+j] != ':' && a[i+j] != '.' && a[i+j] != ',' && a[i+j] != '!' && a[i+j] != '?') continue;
        return 1;
    }
    return 0;
}

void lol() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    cin >> m;
    for (int i = 0; i <= m; i++) {
        getline(cin,r[i]);
        p[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        int x = 0;
        for (int j = 1; j <= n; j++) {
            if (("$"+r[i]).find("$"+s[j]+":") != -1) {
                p[i].insert(s[j]);
                x = 1;
            }
        }
        if (x) continue;
        for (int j = 1; j <= n; j++) {
            if (!ok(r[i],s[j])) p[i].insert(s[j]);
        }
    }
    for (int h = 1; h <= m; h++) {
        for (int i = 1; i <= m; i++) {
            if (p[i].size() == 0) {
                cout << "Impossible\n";
                return;
            }
            if (p[i].size() == 1) {
                p[i-1].erase(*p[i].begin());
                p[i+1].erase(*p[i].begin());
            }
        }
    }
    string v = "";
    for (int i = 1; i <= m; i++) {
        string u = r[i];
        while (u[0] != ':') u = u.substr(1);
        for (auto f = p[i].begin(); f != p[i].end(); f++) {
            if (v != *f) {
                v = *f;
                break;
            }
        }
        cout << v << u << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) lol();
}