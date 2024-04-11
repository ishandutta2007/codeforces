#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    long s = 0;
    long x = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        s += c;
        x ^= c;
    }
    long s0 = s;
    long x0 = x;
    long a = s + x;
//    cout << s << " " << x << " " << a << "\n";
    if (((2 * a - s + a - x) & 1)) a++;
    s = 2 * a - s;
    x = a ^ x;

//    cout << s << " " << x << "\n";

    long q = 0, w = 0, e = 0;
    int c = 0;
    for (int i = 60; i >= 0; i--) {
        long ss = ((s >> i) & 1) + c * 2;
        long xx = ((x >> i) & 1);
        long qq, ww, ee, cc;

        bool ok = false;
        for (int j = 0; j < 8 && !ok; j++) {
            qq = j & 1;
            ww = (j >> 1) & 1;
            ee = (j >> 2) & 1;
            for (cc = 0; cc < 2; cc++) {
                if (((qq ^ ww ^ ee) == xx) && (qq + ww + ee + cc == ss)) {
                    ok = true;
                    break;
                }
            }
        }

        assert(ok);

//        cout << ss << " " << xx << " " << qq << " " << ww << " " << ee << " " << cc << "\n";

        q |= (qq << i);
        w |= (ww << i);
        e |= (ee << i);
        c = cc;
    }
    assert(!c);
    cout << 3 << "\n" << q << " " << w << " " << e << "\n";
    assert(s0 + q + w + e == 2 * (x0 ^ q ^ w ^ e));

}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}