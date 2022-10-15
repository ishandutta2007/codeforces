#include <iostream>
#include <cstdio>

using namespace std;

int n;
int p;
int l[101010];
int r[101010];
double x;

double laske(int a, int b) {
    int l1 = l[a], r1 = r[a];
    int l2 = l[b], r2 = r[b];
    if (l1%p != 0) l1 += p-(l1%p);
    if (l2%p != 0) l2 += p-(l2%p);
    r1 -= r1%p;
    r2 -= r2%p;
    int u1 = r1 >= l1 ? (r1-l1)/p+1 : 0;
    int u2 = r2 >= l2 ? (r2-l2)/p+1 : 0;
    double tn = 1-(double)(r[a]-l[a]+1-u1)/(r[a]-l[a]+1)*(double)(r[b]-l[b]+1-u2)/(r[b]-l[b]+1);
    return tn;
}

int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    for (int i = 1; i <= n-1; i++) x += laske(i,i+1)*1000*2;
    x += laske(1,n)*1000*2;
    printf("%.12f\n", x);
}