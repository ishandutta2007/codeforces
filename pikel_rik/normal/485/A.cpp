#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;

bool isInfinite(int a, int n) {
    unordered_set<int> s;

    s.insert(a % n);
    a += a % n;

    while (a % n != 0) {
        if (s.find(a % n) != s.end())
            return true;
        s.insert(a % n);
        a += a % n;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);

    int a, n;
    cin >> a >> n;

    if (isInfinite(a, n))
        cout << "No\n";
    else cout << "Yes\n";
    return 0;
}