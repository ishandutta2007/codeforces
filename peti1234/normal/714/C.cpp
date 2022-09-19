#include <bits/stdc++.h>

using namespace std;
int n, t[1000002], ert;
char c;
long long x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> c >> x, ert=0;
        for (int j=0; j<18; j++) {
            if (x%2) ert+=(1<<j);
            x/=10;
        }
        if (c=='+') t[ert]++;
        if (c=='-') t[ert]--;
        if (c=='?') cout << t[ert] << "\n";
    }
    return 0;
}