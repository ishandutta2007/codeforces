#include <iostream>
#include <vector>

using namespace std;

int n;
string s;
vector<int> v[10];
int u[202020];

void lol() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < 10; i++) v[i].clear();
    for (int i = 0; i < n; i++) {
        v[s[i]-'0'].push_back(i);
    }
    int k = -1;
    int r = 1;
    for (int i = 0; i < 10; i++) {
        if (v[i].size() == 0) continue;
        if (v[i][0] < k) {
            r++;
            if (r == 3) {
                cout << "-\n";
                return;
            }
            int uk;
            for (auto x : v[i]) {
                if (x < k) {
                    uk = x;
                    u[x] = r;
                } else {
                    u[x] = r-1;
                }
            }
            k = uk;
        } else {
            for (auto x : v[i]) {
                u[x] = r;
                k = x;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << u[i];
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) lol();
}