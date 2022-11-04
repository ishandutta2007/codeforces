#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const double eps = 1e-9;

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i, t;
    ios::sync_with_stdio(false);
    cin >> t;
    while(t > 0) {
        t--;
        double d;
        cin >> d;
        if(4 - d > 0 && d > 0) {
            cout << "N\n";
            continue;
        }
        cout << "Y ";
        double delta = sqrt(1.0 * d * d - 4.0 * d);
        double a, b;
        a = (d + delta) / 2.0;
        b = d - a;
        cout << fixed << setprecision(20) << a << " " << b << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}