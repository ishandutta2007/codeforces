#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, q, m[c], t[c][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i][1];
    }
    cin >> q;
    for (int j=1; j<=q; j++) {
        int a, b, c;
        cin >> a;
        if (a==1) {
            cin >> b >> c;
            t[b][0]=j;
            t[b][1]=c;
        } else {
            cin >> b;
            m[j]=b;
        }
    }
    for (int i=q; i>=0; i--) {
        m[i]=max(m[i], m[i+1]);
    }
    for (int i=1; i<=n; i++) {
        cout << max(t[i][1], m[t[i][0]]) << " ";
    }
    return 0;
}