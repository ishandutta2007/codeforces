#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;

string s;

int rec(int from, int now) {
    if (now >= 1000) {
        return 0;
    }
    if (from > 0 && now % 8 == 0) {
        cout << "YES\n" << now << endl;
        exit(0);
    }
    for (int i = from; i < szof(s); ++i) {
        rec(i + 1, now * 10 + s[i] - '0');
    }
    return 0;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> s;

    rec(0, 0);

    cout << "NO\n";

    return 0;
}