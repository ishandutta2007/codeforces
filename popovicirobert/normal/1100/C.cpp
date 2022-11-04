#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const double pi = acos(-1);

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    double r;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> r;
    cout << fixed << setprecision(20) << 1.0 * r * sin(pi / n) / (1 - sin(pi / n));
    //cin.close();
    //cout.close();
    return 0;
}