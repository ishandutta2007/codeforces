#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, m[2], ki[c][2];
vector<int> x, y;
int holvan(int a, int b) {
    return (ki[a][b] ? ki[a][b]=holvan(ki[a][b], b) : a);
}
void unio(int a, int b, int c) {
    a=holvan(a, c), b=holvan(b, c);
    if (a!=b) {
        ki[a][c]=b;
    }
}
void unio2(int a, int b) {
    unio(a, b, 0), unio(a, b, 1);
    cout << a << " " << b << "\n";
}
bool e(int a, int b, int c) {
    return (holvan(a, c)==holvan(b, c));
}
int main()
{
    cin >> n;
    cin >> m[0] >> m[1];
    for (int id=0; id<2; id++) {
        for (int i=1; i<=m[id]; i++) {
            int a, b;
            cin >> a >> b;
            unio(a, b, id);
        }
    }
    cout << n-1-max(m[0], m[1]) << "\n";
    for (int i=2; i<=n; i++) {
        bool a=e(1, i, 0), b=e(1, i, 1);
        if (!a && !b) {
            unio2(1, i);
        } else {
            if (!a) {
                if (y.size()>0) {
                    unio2(i, y.back());
                    y.pop_back();
                } else {
                    x.push_back(i);
                }
            }
            if (!b) {
                if (x.size()>0) {
                    unio2(i, x.back());
                    x.pop_back();
                } else {
                    y.push_back(i);
                }
            }
        }
        while (x.size()>0 && e(1, x.back(), 0)) {
            x.pop_back();
        }
        while (y.size()>0 && e(1, y.back(), 1)) {
            y.pop_back();
        }
    }
    return 0;
}