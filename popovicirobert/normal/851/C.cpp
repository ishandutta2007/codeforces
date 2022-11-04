#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 1e3;

const long double pi = acos(-1);

struct Point {
    long double a, b, c, d, e;
}pts[MAXN + 1];

inline Point dif(Point x, Point y) {
    return {x.a - y.a, x.b - y.b, x.c - y.c, x.d - y.d, x.e - y.e};
}

inline long double scalar_product(Point x, Point y) {
    return x.a * y.a + x.b * y.b + x.c * y.c + x.d * y.d + x.e * y.e;
}

inline long double lenght(Point x) {
    return sqrt(scalar_product(x, x));
}

inline long double angle(Point x, Point y) {
    return acos(scalar_product(x, y) / (lenght(x) * lenght(y)));
}

bool ok[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j, k;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> pts[i].a >> pts[i].b >> pts[i].c >> pts[i].d >> pts[i].e;
    if(n > 11) {
        cout << 0;
        return 0;
    }
    int ans = n;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            if(i != j)
                for(k = 1; k <= n; k++)
                     if(i != k && j != k) {
                          if(pi * 0.5 - angle(dif(pts[j], pts[i]), dif(pts[k], pts[i])) > 0) {
                              if(ok[i] == 0)
                                 ans--;
                              ok[i] = 1;
                          }
                     }
    }
    cout << ans << endl;
    for(i = 1; i <= n; i++)
        if(ok[i] == 0)
            cout << i << " ";
    //cin.close();
    //cout.close();
    return 0;
}