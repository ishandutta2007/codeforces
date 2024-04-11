#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
int p[555];
int v[555][555];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a][b] = c;
        v[b][a] = c;
    }
    double t = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (v[i][j] == 0) continue;
            double u = (double)(p[i]+p[j])/v[i][j];
            if (u > t) t = u;
        }
    }
    printf("%.15lf\n", t);
}