#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int n, k;
ll x[300000];
int a, b;
ll sa, sb;
ll ma;
ll t;
int pa, pb;
int ak;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> x[i];
    b = k;
    for (int i = 0; i < k; i++) sa += x[i];
    for (int i = k; i < 2*k; i++) sb += x[i];
    ma = sa;
    ak = 0;
    t = sa+sb;
    pa = a; pb = b;
    while (b+k < n) {
        sa = sa-x[a]+x[a+k];
        sb = sb-x[b]+x[b+k];
        if (sa > ma) {
            ma = sa;
            ak = a+1;
        }
        a++; b++;
        if (ma+sb > t) {t = ma+sb; pa = ak; pb = b;}
    }
    cout << (pa+1) << " " << (pb+1) << endl;
}