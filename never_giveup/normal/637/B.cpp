#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 993;

typedef long long ll;

map<string, bool> s;

const int maxn = 2e5;

string q[maxn];

int main(){
    int n;
    cin >> n;
    for (int i = n - 1; i >= 0; i--)
        cin >> q[i];
    for (int i = 0; i < n; i++){
        ll h = 0, st = 1;
        for (int j = 0; j < q[i].length(); j++)
            h = (h + (q[i][j] - 'a' + 1) * st) % mod, st = (st * 29) % mod;
        if (!s[q[i]])
            cout << q[i] << '\n', s[q[i]] = 1;
    }
}