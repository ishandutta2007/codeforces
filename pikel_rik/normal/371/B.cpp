#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    int g = __gcd(a, b);

    a /= g;
    b /= g;

    int c1 = 0;

    while (a % 2 == 0) {
        a /= 2;
        c1 += 1;
    }
    while (a % 3 == 0) {
        a /= 3;
        c1 += 1;
    }
    while (a % 5 == 0) {
        a /= 5;
        c1 += 1;
    }

    int c2 = 0;

    while (b % 2 == 0) {
        b /= 2;
        c2 += 1;
    }
    while (b % 3 == 0) {
        b /= 3;
        c2 += 1;
    }
    while (b % 5 == 0) {
        b /= 5;
        c2 += 1;
    }

    if (a != 1 or b != 1)
        cout << "-1";
    else cout << c1 + c2;
    cout << "\n";
    return 0;
}