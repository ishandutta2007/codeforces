#include <iostream>

using namespace std;

typedef long long ll;

string s;
ll f[128][128];
ll u[128];

int main() {
    cin >> s;
    for (auto c : s) {
        for (char x = 'a'; x <= 'z'; x++) {
            f[x][c] += u[x];
        }
        u[c]++;
    }
    ll h = 0;
    for (char a = 'a'; a <= 'z'; a++) {
        h = max(h,u[a]);
        for (char b = 'a'; b <= 'z'; b++) {
            h = max(h,f[a][b]);
        }
    }
    cout << h << "\n";
}