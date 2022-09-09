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

int n;
vector <int> inp;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        inp.puba(num);
    }

    if (n == 1) {
        if (inp[0] == 0) {
            cout << "YES\n0\n";
        } else {
            cout << "NO\n";
        }
        return 0;
    }

    if (inp[n - 1] == 1) {
        cout << "NO\n";
        return 0;
    }

    if (inp[n - 1] == 0 && inp[n - 2] == 1) {
        cout << "YES\n";
        for (int i = 0; i < n - 1; ++i) {
            cout << inp[i] << "->";
        }
        cout << inp[n - 1] << endl;
        return 0;
    }

    int mem = -1;

    for (int i = n - 3; i >= 0; --i) {
        if (inp[i] == 0) {
            mem = i;
            break;
        }
    }

    if (mem == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    for (int i = 0; i < mem; ++i) {
        cout << inp[i] << "->";
    }
    cout << "(" << inp[mem] << "->";

    if (mem < n - 3) {
        cout << "(";
        for (int i = mem + 1; i < n - 2; ++i) {
            cout << inp[i] << "->";
        }
        cout << inp[n - 2] << ")";
    } else {
        cout << inp[n - 2];
    }
    cout << ")->" << inp[n - 1];
    
    cout << endl;

    return 0;
}