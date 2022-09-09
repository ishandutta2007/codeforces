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

    int lab = -1, rab = -1, lba = -1, rba = -1;

    for (int i = 0; i < szof(s) - 1; ++i) {
        if (lab == -1 && s[i] == 'A' && s[i + 1] == 'B') {
            lab = i;
        }
        if (lba == -1 && s[i] == 'B' && s[i + 1] == 'A') {
            lba = i;
        }
    }

    for (int i = szof(s) - 1; i >= 0; --i) {
        if (rab == -1 && s[i] == 'A' && s[i + 1] == 'B') {
            rab = i;
        }
        if (rba == -1 && s[i] == 'B' && s[i + 1] == 'A') {
            rba = i;
        }
    }

    if (lba == -1 || lab == -1) {
        cout << "NO\n";
        return 0;
    }

    if (lba < rab - 1) {
        cout << "YES\n";
        return 0;
    }

    if (lab < rba - 1) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";

    return 0;
}