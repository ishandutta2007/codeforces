#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-7;

const int N = 1e5 + 123;

int a[N];

int ask(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}

int run() {
    int n;
    cin >> n;
    
    {
        int x = ask(0, 1);
        int y = ask(0, 2);
        int z = ask(1, 2);
        
        a[2] = (y + z - x) / 2;
        a[1] = (x + z - y) / 2;
        a[0] = (x + y - z) / 2;
    }
    
    for (int i = 3; i < n; i++) {
        a[i] = ask(0, i) - a[0];
    }
    
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}