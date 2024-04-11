#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e8;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    if (n == 1) cout << "1\n";
    else if (n == 2) cout << "2\n";

    else if (n % 2 == 0 and n % 3 != 0)
        cout << n * (n - 1) * (n - 3);
    else if (n % 2 == 0 and n % 3 == 0)
        cout << (n - 1) * (n - 2) * (n - 3);
    else cout << n * (n - 1) * (n - 2);

    return 0;
}