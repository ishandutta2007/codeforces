#include <iostream>

using namespace std;

int n, t, k, d;

int lol1() {
    int c = 0;
    for (int i = 1; ; i++) {
        if (i%t == 0) c += k;
        if (c >= n) return i;
    }
}

int lol2() {
    int c = 0;
    for (int i = 1; ; i++) {
        if (i%t == 0) c += k;
        if (i > d && (i-d)%t == 0) c += k;
        if (c >= n) return i;
    }
}

int main() {
    cin >> n >> t >> k >> d;
    if (lol1() == lol2()) cout << "NO\n";
    else cout << "YES\n";
}