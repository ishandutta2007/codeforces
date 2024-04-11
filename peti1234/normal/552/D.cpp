#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int n, x[c], y[c];
long long mind, rossz;
map<pair<int, int>, int> m;
int main()
{
    cin >> n;
    mind=(long long)n*(n-1)*(n-2)/6;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=1; i<=n; i++) {
        m.clear();
        for (int j=i+1; j<=n; j++) {
            int a=x[j]-x[i], b=y[j]-y[i], oszt=__gcd(a, b);
            a/=oszt, b/=oszt;
            if (a<0) {
                a*=-1, b*=-1;
            }
            rossz+=m[{a, b}];
            m[{a, b}]++;
        }
    }
    cout << mind-rossz << "\n";
    return 0;
}