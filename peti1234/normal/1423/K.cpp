#include <bits/stdc++.h>

using namespace std;
const int c=1e6+2;
int db[c], p[c], n, x, y;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i=2; i<c; i++) {
        if (!p[i]) {
            for (int j=2*i; j<c; j+=i) p[j]=1;
        }
    }
    for (int i=2; i<c; i++) {
        db[i]=db[i-1]+(1-p[i]);
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x, y=sqrt(x);
        cout << db[x]-db[y]+1 << "\n";
    }
    return 0;
}