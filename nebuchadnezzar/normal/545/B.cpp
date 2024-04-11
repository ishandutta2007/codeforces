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

string s1, s2;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> s1 >> s2;

    int num = 0;

    for (int i = 0; i < szof(s1); ++i) {
        if (s1[i] != s2[i]) {
            ++num;
        }
    }

    if (num & 1) {
        cout << "impossible" << endl;
        return 0;
    }

    int num2 = 0;
    for (int i = 0; i < szof(s1); ++i) {
        if (s1[i] == s2[i]) {
            cout << s1[i];
            continue;
        }
        if (num2 < num / 2) {
            cout << s1[i];
            ++num2;
        } else {
            cout << s2[i];
        }
    }

    cout << endl;

    return 0;
}