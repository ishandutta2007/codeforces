#include <bits/stdc++.h>

using namespace std;
long long po[39], ks[39], q, n, sol;
int main()
{
    po[0]=1;
    for (int i=1; i<=38; i++) po[i]=po[i-1]*3, ks[i]=ks[i-1]+po[i-1];
    ios_base::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n, sol=0;
        for (int i=38; i>=0; i--) {
            if (n>ks[i]) {
                sol+=po[i], n-=po[i];
            }
        }
        cout << sol << "\n";
    }
    return 0;
}