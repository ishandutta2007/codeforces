#include <iostream>
#include <vector>

using namespace std;

int n, k;
string s;
int p;
int c1[101010];
int c2[101010];

bool ok(int u) {
    for (int i = 1; i+u <= n+1; i++) {
        int x1 = c1[i+u-1]-c1[i-1];
        int x2 = c2[i+u-1]-c2[i-1];
        if (x1 <= k || x2 <= k) return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    cin >> s;
    s = "*"+s;
    for (int i = 1; i <= n; i++) {
        c1[i] = c1[i-1];
        c2[i] = c2[i-1];
        if (s[i] == 'a') c1[i]++;
        if (s[i] == 'b') c2[i]++;
    }
    int u = 0;
    for (int b = n; b >= 1; b /= 2) {
        while (u+b <= n && ok(u+b)) u += b;
    }
    cout << u << "\n";
}