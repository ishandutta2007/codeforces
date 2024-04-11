#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

#define ll long long
int X;
#define MP make_pair
#define F first
#define S second

struct P {
    int l, r, k;
};

bool cmp(P a, P b) {
    if (a.l/X == b.l/X) return a.r < b.r;
    else return a.l < b.l;
}

int n, t;
int a[1010101];
P v[202020];
ll z[202020];

ll s;
int q[1010101];

int main() {
    scanf("%i %i", &n, &t);
    X = sqrt(n);
    for (int i = 0; i < n; i++) scanf("%i", &a[i]);
    for (int i = 0; i < t; i++) {
        int l, r;
        scanf("%i %i", &l, &r);
        l--; r--;
        v[i].l = l;
        v[i].r = r;
        v[i].k = i;
    }
    sort(v, v+t, cmp);
    int l = 0, r = -1;
    for (int i = 0; i < t; i++) {
        int ur = v[i].r;
        int ul = v[i].l;
        int ui = v[i].k;
        while (r < ur) {
            r++;
            s += a[r]*(2*q[a[r]]+1);
            q[a[r]]++;
        }
        while (r > ur) {
            s -= a[r]*(2*q[a[r]]-1);
            q[a[r]]--;
            r--;
        }
        while (l > ul) {
            l--;
            s += a[l]*(2*q[a[l]]+1);
            q[a[l]]++;
        }
        while (l < ul) {
            s -= a[l]*(2*q[a[l]]-1);
            q[a[l]]--;
            l++;
        }
        z[ui] = s;
    }
    for (int i = 0; i < t; i++) printf("%I64d\n", z[i]);
}