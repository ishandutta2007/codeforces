#include <iostream>

using namespace std;

#define N (1<<18)

int p[2*N];

void setVal(int k, int x) {
    k += N;
    p[k] = x;
    for (k /= 2; k >= 1; k /= 2) p[k] = max(p[2*k],p[2*k+1]);
}

int maxVal(int a, int b) {
    a += N; b += N;
    int u = 0;
    while (a <= b) {
        if (a%2 == 1) u = max(u,p[a++]);
        if (b%2 == 0) u = max(u,p[b--]);
        a /= 2; b /= 2;
    }
    return u;
}

int n;
int a[202020];
int q;
int f[202020];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            a[p] = x;
            f[p] = i;
        } else {
            int x;
            cin >> x;
            setVal(i,x);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << max(a[i],maxVal(f[i],q)) << " ";
    }
    cout << "\n";
}