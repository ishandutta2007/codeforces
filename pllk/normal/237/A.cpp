#include <iostream>

using namespace std;

int n;
int va, vb, ua, ub;
int t, m;

int main() {
    cin >> n;
    va = -1; vb = -1;
    t = 0; m = 1;
    for (int i = 0; i < n; i++) {
        cin >> ua >> ub;
        if (va == ua && vb == ub) {
            t++;
            if (t > m) m = t;
        } else {
            t = 1;
            va = ua; vb = ub;
        }
    }
    cout << m << endl;
}