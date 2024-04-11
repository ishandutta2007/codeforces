#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct vec {
    ld x, y;
    vec() {

    }
    vec(ld x, ld y) {
        this->x = x;
        this->y = y;
    }
    vec(vec a, vec b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    void mul(ld k) {
        x *= k;
        y *= k;
    }
    ld len() {
        return sqrt(x * x + y * y);
    }
    void normalise() {
        ld k = this->len();
        if (k > 0) {
            x /= k;
            y /= k;
        } else x = 1;
    }
};

ld len(vec a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

vec operator+(vec a, vec b) {
    return vec(a.x + b.x, a.y + b.y);
}

int main() {
    ld R;
    vec p1, p2;
    cin >> R >> p1.x >> p1.y >> p2.x >> p2.y;
    vec toc = vec(p2, p1);
    if (toc.len() >= R) {
        cout << fixed << setprecision(20) << p1.x << ' ' << p1.y << ' ' << R - 0.0000000001;
        //system("pause");
        return 0;
    }
    vec rad = toc;
    rad.normalise();
    rad.mul(R);
    toc = toc + rad;
    toc.mul(0.5);
    cout << fixed << setprecision(20) << p2.x + toc.x << ' ' << p2.y + toc.y << ' ' << toc.len() - 0.0000000001;
    //system("pause");
    return 0;
}