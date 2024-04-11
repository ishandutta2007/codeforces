#include <bits/stdc++.h>

using namespace std;
const int c=505;
string a, b;
int n, m, t[c];
long long regi[c], uj[c], mod=1e9+7;
void solve() {
    cin >> a >> b;
    n=a.size(), m=b.size();
    regi[0]=1;
    bool spec=0;
    for (int i=0; i<n-m+1; i++) {
        if (a.substr(i, m)==b) {
            spec=1;
            t[i+1]=1;
        }
    }
    if (!spec) {
        cout << 0 << " " << 1 << "\n";
        return;
    }
    int lep=0;
    while (true) {
        lep++;
        for (int i=1; i<=n; i++) {
            if (t[i]) {
                for (int j=i-1; j>=0; j--) {
                    uj[i+m-1]=(uj[i+m-1]+regi[j])%mod;
                    if (j+m<=i && t[j]) break;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            regi[i]=uj[i];
            uj[i]=0;
        }
        long long sum=0;
        for (int i=n; i>=0; i--) {
            sum+=regi[i];
            if (t[i]) break;
        }
        if (sum) {
            cout << lep << " " << sum%mod << "\n";
            break;
        }
    }

    memset(t, 0, sizeof(t));
    memset(regi, 0, sizeof(regi));
    memset(uj, 0, sizeof(uj));
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
abababacababa
aba
*/