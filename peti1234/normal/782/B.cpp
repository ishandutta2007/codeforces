#include <bits/stdc++.h>

using namespace std;
int n;
long long t[60001];
long long v[60001];
double a=0, b=1000000000;
bool lehet(double x)
{
    double maxi=0, mini=INT_MAX;
    for (int i=1; i<=n; i++) {
        mini=min(mini, t[i]+v[i]*x);
        maxi=max(maxi, t[i]-v[i]*x);
    }
    return mini>=maxi;
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    while ((b-a)/max(1.0, a)>=1.0e-6) {
        if (lehet((a+b)/2)) {
            b=(a+b)/2;
        } else {
            a=(a+b)/2;
        }
    }
    cout << fixed << setprecision(9) << b << endl;
    return 0;
}