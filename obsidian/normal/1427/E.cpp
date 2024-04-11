#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

const int V = 100100;
const int N = 2;

LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    LL r=exgcd(b,a%b,x,y);
    LL temp=y;
    y=x-(a/b)*y;
    x=temp;
    return r;
}

LL gcd(LL x, LL y) {
    if (!x) return y;
    if (!y) return x;
    return gcd(y, x % y);
}
LL a[V];
LL x[V], z[V];
char y[V];
int n, m, K;

void add(LL X, char Y, LL Z) {
    x[m] = X;
    y[m] = Y;
    z[m++] = Z;
}

void get(LL v, LL mul) {
    LL res = 1;
    while (res < mul) {
        add(v * res, '+', v * res);
        res *= 2;
    }
    LL tmp = 1;
    LL tr = v;
    --mul;
    while (mul) {
        if (mul & 1) add(tr, '+', v * tmp), tr += v * tmp;
        mul /= 2; tmp *= 2;
    }
}

void process(LL L, LL R) {
    LL tx, ty;
    exgcd(L, R, tx, ty);
    ty = -ty;
    LL ADD = max((1 - tx + R - 1) / R,(1 - ty + L - 1) / L);
    ADD = max(ADD, 0LL);
    tx += R * ADD;
    ty += L * ADD;
    get(L, tx);
    get(R, ty);
    LL X = L * tx;
    LL Y = R * ty;
    if ((X ^ Y) != 1) {
        add(X, '+', K);
        add(Y, '+', K);
        X += K;
        Y += K;
    }
    add(X, '^', Y);
}

int main() {
    while (~scanf("%d", &K)) {
        a[0] = K;
        n = 1;
        m = 0;
        while (true) {
            LL L = -1LL, R = -1LL;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (gcd(a[i], a[j]) == 1) {
                        if (L == -1LL || max(a[i], a[j]) < max(L, R)) {
                            L = a[i];
                            R = a[j];
                        }
                    }
                }
            }
            if (L != -1LL) {
                //printf("LR %I64d %I64d\n", L, R);
                process(L, R);
                break;
            }
            LL base = a[n - 1];
            for (int i = 2; i <= N; ++i) {
                x[m] = base;
                y[m] = '+';
                z[m++] = base * (i - 1);
                a[n++] = i * base;
            }
            for (int i = 2; i <= N; ++i) {
                x[m] = base;
                y[m] = '^';
                z[m++] = base * i;
                a[n++] = base ^ (i * base);
            }
            //for (int i = 0; i < n; ++i) printf("%I64d ", a[i]); puts("");
        }
        printf("%d\n", m);
        for (int i = 0; i < m; ++i) printf("%I64d %c %I64d\n", x[i], y[i], z[i]);
    }
    return 0;
}

/*

*/