#include <bits/stdc++.h>

using namespace std;
long long w, n;
long double sum;
vector<long double> a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        a.clear(), b.clear(), sum=0;
        for (int i=0; i<2*n; i++) {
            long long x, y;
            cin >> x >> y;
            if (!x) {
                a.push_back(abs(y));
            } else {
                b.push_back(abs(x));
            }
        }
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        for (int i=0; i<n; i++) {
            sum+=sqrt(a[i]*a[i]+b[i]*b[i]);
        }
        cout.precision(20);
        cout << sum << "\n";
    }
    return 0;
}
/*
1
1
100000000 0
0 100000000
*/