#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 1000;

double a[MAXN], b[MAXN];
int n;

inline bool check(double fuel, double m) {
    for(int i = 0; i < n; i++) {
        double aux = fuel;
        fuel -= (m / a[i]);
        m -= (aux - fuel);
        aux = fuel;
        fuel -= (m / b[(i + 1) % n]);
        m -= (aux - fuel);
    }
    return fuel >= 0.0;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(i = 0; i < n; i++) {
        cin >> b[i];
    }
    double l = 0, r = 2e9;
    for(i = 0; i < 500; i++) {
        double mid = (l + r) * 0.5;
        if(check(mid, mid + m) == 0) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    double mid = (l + r) * 0.5;
    if(check(r, r + m) == 0) {
        cout << -1;
        return 0;
    }
    cout << fixed << setprecision(20) << mid;
    //cin.close();
    //cout.close();
    return 0;
}