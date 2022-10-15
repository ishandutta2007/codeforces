#include <iostream>
#include <set>

using namespace std;

int n;
int p[202020];
int a[202020];
int b[202020];
int m;

set<pair<int,int>> s[4];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            if (a[i] == j || b[i] == j) {
                s[j].insert({p[i],i});
            }
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int c;
        cin >> c;
        if (s[c].size() == 0) {
            cout << "-1 ";
            continue;
        }
        auto u = *s[c].begin();
        int up = u.first;
        int ui = u.second;
        for (int j = 1; j <= 3; j++) s[j].erase({up,ui});
        cout << up << " ";
    }
    cout << "\n";
}