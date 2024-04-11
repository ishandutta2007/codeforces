#include <bits/stdc++.h>

using namespace std;
long long n, m, s;
long double ert, dif;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        double s=i;
        ert+=(pow(s/n, m)-pow((s-1)/n, m))*s;
    }
    cout.precision(20);
    cout << ert << endl;
}