#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = n % 7, c = n / 7;

    while (c and sum % 4) {
        sum += 7;
        c -= 1;
    }

    if (sum % 4 == 0) {
        for (int i = 0; i < sum / 4; i++) cout << '4';
        for (int i = 0; i < c; i++) cout << '7';
        cout << "\n";
    }
    else cout << "-1\n";
    return 0;
}