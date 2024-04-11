#include <bits/stdc++.h>

using namespace std;
int n, o, na, mo, mn;
int t[100001];
int f[100001];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        while (t[i]-89>t[o]) {
            mo-=f[o];
            o++;
        }
        while (t[i]-1439>t[na]) {
            mn-=f[na];
            na++;
        }
        f[i]=min(20, min(50-mo, 120-mn));
        mn+=f[i];
        mo+=f[i];
    }
    for (int i=1; i<=n; i++) {
        cout << f[i] << endl;
    }
    return 0;
}