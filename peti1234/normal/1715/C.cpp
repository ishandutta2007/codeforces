#include <bits/stdc++.h>

using namespace std;
long long n, q, sum, t[100005];
void calc(long long pos, long long p) {
    if (pos==0 || pos==n) return;
    if (t[pos]!=t[pos+1]) {
        sum+=p*pos*(n-pos);
    }
}
int main()
{
    cin >> n >> q;
    sum=n*(n+1)/2;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (long long i=1; i<n; i++) {
        if (t[i]!=t[i+1]) {
            calc(i, 1);
        }
    }
    for (int i=1; i<=q; i++) {
        long long pos, ert;
        cin >> pos >> ert;
        calc(pos-1, -1);
        calc(pos, -1);
        t[pos]=ert;
        calc(pos-1, 1);
        calc(pos, 1);
        cout << sum << "\n";
    }
    return 0;
}