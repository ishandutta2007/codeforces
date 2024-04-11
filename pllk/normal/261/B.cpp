#include <iostream>

#define ll long long int

using namespace std;

int n;
int a[50];
int p;

int v[60][60][60];
ll d[60][60][60];

ll laske(int s, int m, int k) {
    if (s == 0 && m == 0 && k == -1) return 1;
    if (k == -1) return 0;
    if (v[s][m][k]) return d[s][m][k];
    ll t = 0;
    if (s-a[k] >= 0 && m-1 >= 0) t += laske(s-a[k], m-1, k-1);
    t += laske(s, m, k-1);
    v[s][m][k] = 1;
    d[s][m][k] = t;
    return t;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> p;
    double s = 0;
    for (int a = 1; a <= n; a++) {
        ll q = 0;
        for (int b = 1; b <= p; b++) q += laske(b, a, n-1);
        ll w = 0;
        if (a == n) goto ohi;
        for (int b = 1; b <= p; b++) w += laske(b, a+1, n-1);
        ohi:
        double t = (n-a)*q-(a+1)*w;
        if (a == n) t = q;
        int h = 1;
        for (int i = 1; i <= a; i++) {
            t *= i; t /= h;
            h++;
        }
        for (int i = 1; i <= n-a-1; i++) {
            t *= i; t /= h;
            h++;
        }
        while (h <= n) {
            t /= h;
            h++;
        }
        s += t*a;
    }
    cout << s << endl;
}