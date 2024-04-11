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

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> s;

    for (int i = 0; i < szof(s); ++i) {
        for (int j = i + 1; j <= szof(s); ++j) {
            string ns;
            for (int k = 0; k < i; ++k) {
                ns += s[k];
            }
            for (int k = j; k < szof(s); ++k) {
                ns += s[k];
            }
            if (ns == "CODEFORCES") {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

    return 0;
}