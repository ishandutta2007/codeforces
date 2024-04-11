#include <iostream>
#include <algorithm>

using namespace std;

int n, x;
int s;

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        s += q;
    }
    s = abs(s);
    if (s == 0) cout << 0 << endl;
    else if (s%x == 0) cout << s/x << endl;
    else cout << s/x+1 << endl;
}