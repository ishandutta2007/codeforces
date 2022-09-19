#include <bits/stdc++.h>

using namespace std;
long long n, x[5002], y[5002], el, pos;
bool v[5002];
long long tav(int a, int b) {
    return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (!v[j] && tav(el, j)>=tav(el, pos)) {
                pos=j;
            }
        }
        el=pos, v[el]=1;
        cout << el << " ";
    }
    cout << "\n";
    return 0;
}