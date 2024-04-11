#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, m[2], ki[c][2];
int holvan(int a, int b) {
    return (ki[a][b] ? ki[a][b]=holvan(ki[a][b], b) : a);
}
void unio(int a, int b, int c) {
    a=holvan(a, c), b=holvan(b, c);
    if (a!=b) {
        ki[a][c]=b;
    }
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
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (holvan(i, 0)!=holvan(j, 0) && holvan(i, 1)!=holvan(j, 1)) {
                cout << i << " " << j << "\n";
                unio(i, j, 0), unio(i, j, 1);
            }
        }
    }
    return 0;
}