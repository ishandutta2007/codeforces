#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll A, cf, cm, m;
int a[101010];
pair<int,int> pp[101010];
ll s[101010];
ll p;
int rr[101010];

bool ok(int k, ll u) {
    if (a[n] >= u) return true;
    int d = k-1;
    for (int b = n; b >= 1; b /= 2) {
        while (d+b <= n && a[d+b] >= u) d += b;
    }
    ll h = u*(n-d)-(s[n]-s[d]);
    return m >= h;
}

int etsi(int k) {
    if (k == n+1) return A;
    ll t = 0;
    for (int b = A; b >= 1; b /= 2) {
        while (t+b <= A && ok(k,t+b)) t += b;
    }
    return t;
}

int main() {
    cin >> n >> A >> cf >> cm >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pp[i] = {a[i],i};
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    sort(pp+1, pp+n+1);
    reverse(pp+1, pp+n+1);
    for (int i = 1; i <= n; i++) s[i] = s[i-1]+a[i];
    p = etsi(1)*cm;
    int aa = 0;
    int bb = etsi(1);
    for (int i = 1; i <= n; i++) {
        m -= (A-a[i]);
        if (m < 0) break;
        ll u = i*cf+etsi(i+1)*cm;
        if (u > p) {
            p = u;
            aa = i;
            bb = etsi(i+1);
        }
    }
    cout << p << "\n";
    for (int i = 1; i <= n; i++) {
        if (i <= aa) rr[pp[i].second] = A;
        else if (a[i] < bb) rr[pp[i].second] = bb;
        else rr[pp[i].second] = a[i];
    }
    for (int i = 1; i <= n; i++) cout << rr[i] << " ";
    cout << "\n";
}