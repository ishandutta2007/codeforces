#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pi> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    int cur = a[0].first;
    int c = 2;

    for (int i = 1; i < n - 1; i++) {
        if (a[i].first - a[i].second > cur) {
            cur = a[i].first;
            c += 1;
        }
        else if (a[i].first + a[i].second < a[i+1].first) {
            cur = a[i].first + a[i].second;
            c += 1;
        }
        else cur = a[i].first;
    }

    if (n == 1)
        c -= 1;
    cout << c;

    return 0;
}