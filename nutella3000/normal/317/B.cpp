#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
struct crd {
    int x,y;
    crd(int x1,int y1) {
        x = x1;
        y = y1;
    }
    crd() {}
};
int main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[201][201];
    for(int i = 0;i < 201;i++) {
        for(int j = 0;j < 201;j++) {
            a[i][j] = 0;
        }
    }
    a[100][100] = n;
    for(int cnt = 0;cnt < 5000;cnt++) {
        for (int i = 1; i < 200; i++) {
            for (int j = 1; j < 200; j++) {
                int u = a[i][j] / 4;
                a[i - 1][j] += u;
                a[i + 1][j] += u;
                a[i][j - 1] += u;
                a[i][j + 1] += u;
                a[i][j] %= 4;
            }
        }
    }
    int q;
    cin >> q;
    for(int i = 0;i < q;i++) {
        int x,y;
        cin >> x >> y;
        x += 100;
        y += 100;
        if (x < 0 || y < 0 || x > 200 || y > 200) cout << 0 << '\n';
        else cout << a[x][y] << '\n';
    }
}