#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second

using namespace std;

struct Circle {
    long double x, y;
    long double r;
}A, B;

inline long double SquareDist(pair <long double, long double> a, pair <long double, long double> b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

inline long double Dist(pair <long double, long double> a, pair <long double, long double> b) {
    return sqrt(SquareDist(a, b));
}

const long double pi = acos(-1);

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    ios::sync_with_stdio(false);
    cin >> A.x >> A.y >> A.r;
    cin >> B.x >> B.y >> B.r;
    if(A.r > B.r)
        swap(A, B);
    if(SquareDist({A.x, A.y}, {B.x, B.y}) >= (A.r + B.r) * (A.r + B.r))
        cout << setprecision(20) << 0;
    else if(SquareDist({A.x, A.y}, {B.x, B.y}) <= (B.r - A.r) * (B.r - A.r))
        cout << setprecision(20) << pi * A.r * A.r;
    else {
        long double d = Dist({A.x, A.y}, {B.x, B.y});
        long double ang = acos((A.r * A.r + SquareDist({A.x, A.y}, {B.x, B.y}) - B.r * B.r) / (2.0 * A.r * d));
        long double ans = A.r * A.r * (ang - sin(2 * ang) / 2.0);
        ang = acos((B.r * B.r + SquareDist({A.x, A.y}, {B.x, B.y}) - A.r * A.r) / (2.0 * B.r * d));
        ans += B.r * B.r * (ang - sin(2 * ang) / 2.0);
        cout << setprecision(20) << ans;
    }
    //cin.close();
    //cout.close();
    return 0;
}