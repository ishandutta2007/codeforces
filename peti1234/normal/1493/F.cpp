#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int n, m, sum=1, db;
bool pr[c];
bool ask(int a, int b, int c, int d, int e, int f) {
    cout << "? " << a << " " << b << " " << c << " " << d << " " << e << " " << f;
    cout.flush() << "\n";
    bool x; cin >> x;
    return x;
}
int ch(bool p, int ert, int t) {
    if (t%ert) {
        return 0;
    }
    int f=t/ert*(ert/2), s=t/ert;
    bool a=0, b=0;
    if (p) {
        a=ask(f, m, 1, 1, f+1, 1);
    } else {
        a=ask(n, f, 1, 1, 1, f+1);
    }
    if (ert==2) {
        if (!a) {
            return 0;
        }
        return 1+ch(p, ert, t/ert);
    }
    if (p) {
        b=ask(f, m, s+1, 1, s+f+1, 1);
    } else {
        b=ask(n, f, 1, s+1, 1, s+f+1);
    }
    if (!a || !b) {
        return 0;
    }
    return 1+ch(p, ert, t/ert);
}
int main()
{
    for (int i=2; i<c; i++) {
        if (!pr[i]) {
            for (int j=2*i; j<c; j+=i) {
                pr[j]=1;
            }
        }
    }
    cin >> n >> m;
    for (int i=2; i<=n; i++) {
        if (!pr[i]) {
            sum*=1+ch(1, i, n);
        }
    }
    for (int i=2; i<=m; i++) {
        if (!pr[i]) {
            sum*=1+ch(0, i, m);
        }
    }
    cout << "! " << sum << "\n";
    return 0;
}