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

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    if (n == 1 || n == 2) {
        cout << "1\n1\n";
        return 0;
    }

    if (n == 3) {
        cout << "2\n1 3\n";
        return 0;
    }

    if (n == 4) {
        cout << "4\n3 1 4 2\n";
        return 0;
    }

    if (n % 2 == 0) {
        cout << n << endl;
        for (int i = 0; i < n / 2; ++i) {
            cout << i + 1 << " " << i + n / 2 + 1 << " ";
        }
        cout << endl;
        return 0;
    }

    cout << n << endl;
    for (int i = 0; i < n / 2; ++i) {
        cout << i + 1 << " " << i + n / 2 + 2 << " ";
    }
    cout << n / 2 + 1 << endl;
    return 0;


    return 0;
}