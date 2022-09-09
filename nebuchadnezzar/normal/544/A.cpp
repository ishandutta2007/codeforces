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

int k;
string s;
bool used[26];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //              sauron1love
    cin >> k >> s;
    vector <int> v;

    for (int i = 0; i < szof(s); ++i) {
        if (!used[s[i] - 'a']) {
            v.puba(i);
            used[s[i] - 'a'] = true;
        }
    }

    if (szof(v) < k) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    v.resize(k);
    v.puba(szof(s));

    for (int i = 0; i < k; ++i) {
        for (int j = v[i]; j < v[i + 1]; ++j) {
            cout << s[j];
        }
        cout << endl;
    }

    return 0;
}