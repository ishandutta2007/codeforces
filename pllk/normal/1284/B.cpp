#include <iostream>

using namespace std;

typedef long long ll;

int n;
int u[1222333];
int r[1222333];
int g[1222333];
int s[1222333];
int q[1222333];

int main() {
    cin >> n;
    ll v = 0;
    int f = 0;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        int a, b;
        bool ok = false;
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            if (j == 1) a = b = x;
            if (x > a) ok = true;
            if (x < a) a = x;
            if (x > b) b = x;
        }
        if (ok) {r[i] = 1; f++;}
        else u[a]++;
        q[i] = b;
    }
    s[0] = u[0];
    for (int i = 1; i <= 1000000; i++) {
        s[i] = s[i-1]+u[i];
    }
    for (int i = 1; i <= n; i++) {
        int x = q[i];
        int w = v;
        if (r[i]) v += n;
        else v += f+s[x-1];
    }
    cout << v << "\n";
}