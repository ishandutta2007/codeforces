#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

LL n, k;

LL get(int pos) {
    cout << "? " << pos + 1 << endl;
    LL val;
    cin >> val;
    return val;
}

void ans(int pos) {
    cout << "! " << pos + 1 << '\n';
    exit(0);
}

void ask(int pos) {
    LL val = get(pos);
    if (val == k)
        return;
    int dx = val < k ? +1 : n - 1;
    while (true) {
        pos = (pos + dx) % n;
        if (get(pos) == k)
            ans(pos);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int pos;
    for (int i = 0; i < 100; i++)
        pos = rand();
    pos %= n;
    get(0);
    for (int i = 0; true; i++) {
        pos += i;
        if (pos >= n)
            pos -= n;
        ask(pos);
    }
    return 0;
}