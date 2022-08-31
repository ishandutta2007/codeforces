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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    //if a == b, max(c, d) fit to a or b
    //if c == d min(a, b) fit to c or d

    int p, q;
    if (a * d > b * c) {
        int new_c = (c * b) / d; //4 3 2 2
        int new_d = b;
        p = (a * d - c * b);
        q = a * d;
        int g = __gcd(p, q);
        p /= g;
        q /= g;

        cout << p << "/" << q << "\n";
    }
    else {
        int new_c = a; //3 4 2 2
        int new_d = (d * a) / c;
        p = (b * c - a * d);
        q = b * c;
        p = (p < 0 ? -p : p);
        int g = __gcd(p, q);
        p /= g;
        q /= g;

        cout << p << "/" << q << "\n";
    }
    return 0;
}