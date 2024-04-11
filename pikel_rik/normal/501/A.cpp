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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans1 = max(3 * a / 10, a - (a / 250) * c);
    int ans2 = max(3 * b / 10, b - (b / 250) * d);

    if (ans1 > ans2)
        cout << "Misha\n";
    else if (ans1 < ans2)
        cout << "Vasya\n";
    else cout << "Tie\n";

    return 0;
}