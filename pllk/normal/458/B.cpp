#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int m, n;
int a[101010];
int b[101010];
ll s1, s2;
ll t1, t2;

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        s1 += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s2 += b[i];
    }
    sort(a, a+m);
    reverse(a, a+m);
    sort(b, b+n);
    reverse(b, b+n);
    int c = m;
    for (int i = m-1; i >= 1; i--) {
        if (a[i] < s2) {t1 += a[i]; c--;}
    }
    t1 += c*s2;
    c = n;
    for (int i = n-1; i >= 1; i--) {
        if (b[i] < s1) {t2 += b[i]; c--;}
    }
    t2 += c*s1;
    cout << min(t1, t2) << "\n";
}