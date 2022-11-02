#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

#define cerr if (true) {} else cout
#define pisz(x) cout << #x << ": " << x << endl;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, nn;
    cin >> n;
    nn = n;
    int ile = 0;
    int jak = n;
    for (int i = 2; i < min(nn, 1000010ll); i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            ile++;
            jak = i;
        }
    }

    if (n > 1 && n != nn) ile++;

    if (ile > 1) {
        cout << 1;
        return 0;
    }
    cout << jak << endl;


    return 0;
}
/*

*/