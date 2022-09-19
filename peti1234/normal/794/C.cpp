#include <bits/stdc++.h>

using namespace std;
int n, ka, va, kb, vb, e, v;
string a, b, sol;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    n=a.size(), sol.resize(n), v=n-1;
    sort(a.begin(), a.end()), sort(b.rbegin(), b.rend());
    va=(n-1)/2, vb=(n-2)/2;
    for (int i=0; i<n; i++) {
        if (i%2==0) {
            if (a[ka]<b[kb]) {
                sol[e]=a[ka];
                ka++, e++;
            } else {
                sol[v]=a[va];
                va--, v--;
            }
        } else {
            if (a[ka]<b[kb]) {
                sol[e]=b[kb];
                kb++, e++;
            } else {
                sol[v]=b[vb];
                vb--, v--;
            }
        }
    }
    cout << sol << endl;
    return 0;
}