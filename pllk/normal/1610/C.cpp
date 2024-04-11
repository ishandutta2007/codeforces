#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a, b;

bool check(int x) {
    int ra = 0;
    int rb = x-1;
    int c = 0;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] >= ra && b[i] >= rb) {
            ra++; rb--; c++;
        }
        if (c == x) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
        int k = 0;
        for (int b = n; b >= 1; b /= 2) {
            while (k+b <= n && check(k+b)) k += b;
        }
        cout << k << "\n";
    }
}