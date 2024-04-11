#include <bits/stdc++.h>
using namespace std;

bool uda[102][102][102];

struct rps {
    double a, b, c;
    rps () {
        a = b = c = 0;
    }

    rps operator * (int other) const {
        rps ret;
        ret.a = a * other;
        ret.b = b * other;
        ret.c = c * other;
        return ret;
    }

    rps operator + (rps other) const {
        rps ret;
        ret.a = a + other.a;
        ret.b = b + other.b;
        ret.c = c + other.c;
        return ret;
    }

    rps operator / (int other) const {
        rps ret;
        ret.a = a / other;
        ret.b = b / other;
        ret.c = c / other;
        return ret;
    }
};

rps dp[102][102][102];

rps f(int x, int y, int z) {
    rps tmp;
    if (x < 0 || y < 0 || z < 0) return tmp;
    if (x == 0 && y == 0) {
        tmp.c = 1;
        return tmp;
    }
    if (x == 0 && z == 0) {
        tmp.b = 1;
        return tmp;
    }
    if (y == 0 && z == 0) {
        tmp.a = 1;
        return tmp;
    }

    if (uda[x][y][z]) return dp[x][y][z];
    uda[x][y][z] = 1;

    return dp[x][y][z] = (f(x-1, y, z) * x * z + f(x, y-1, z) * x * y + f(x, y, z-1) * y * z) / (x * y + x * z + y * z);
}

int r, p, s;

int main() {
    scanf("%d %d %d", &r, &p, &s);
    rps ans = f(r, p, s);
    printf("%.12lf %.12lf %.12lf\n", ans.a, ans.b, ans.c);
    return 0;
}