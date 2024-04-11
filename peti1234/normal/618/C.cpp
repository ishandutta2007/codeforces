#include <bits/stdc++.h>

using namespace std;
const int cc=100005;
long long x[cc], y[cc], n, a=1, b=2, c;
long long tav(int a, int b) {
    long long ans=(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
    return ans;
}
bool jo(int a, int b, int c) {
    long long s=(x[b]-x[a])*(y[c]-y[a])-(x[c]-x[a])*(y[b]-y[a]);
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=3; i<=n; i++) {
        if (tav(i, a)<tav(b, a)) {
            b=i;
        }
    }
    for (int i=1; i<=n; i++) {
        if (jo(a, b, i) && (c==0 || tav(a, i)<tav(a, c))) {
            c=i;
        }
    }
    cout << a << " " << b << " " << c << "\n";
    return 0;
}