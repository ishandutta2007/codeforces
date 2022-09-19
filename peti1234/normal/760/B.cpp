#include <bits/stdc++.h>

using namespace std;
long long n, m, k, sz=1, f=1;
int main()
{
    cin >> n >> m >> k;
    m-=n;
    while (m-sz>=0) {
        m-=sz;
        f++;
        if (k+f-1<=n) {
            sz++;
        }
        if (k-f+1>=1) {
            sz++;
        }
        if (sz==n) {
            f+=m/sz;
            cout << f << endl;
            return 0;
        }
    }
    cout << f << endl;
    return 0;
}