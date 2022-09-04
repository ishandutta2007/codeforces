#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll q[5000], a[2000], n, p[10000];

string Get(long double n)
{
    ostringstream os;

    os.setf(ios::fixed);
    os.precision(2);
    os << n;
    return os.str();
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            q[a[j] - a[i]]++;
    for (int i = 0; i < a[n - 1]; i++)
    for (int j = 0; j < a[n - 1]; j++){
        p[i + j] += q[i] * q[j];
    }
    for (int i = 1; i < a[n - 1] * 2; i++)
        p[i] += p[i - 1];
    ll all = 0, good = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            all++, good += p[a[j] - a[i] - 1];
    long double g = good, al = all * all * all;
    g /= al;
    cout << setprecision(20) << (double)g;
}