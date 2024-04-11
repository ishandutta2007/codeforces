#include <bits/stdc++.h>

using namespace std;
long long n, k, t[200005];
void solve() {
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    t[0]=0, t[n+1]=0;
    long long sum=t[k], bal=k, jobb=k, bs=0, js=0;
    while (true) {
        bool jo=0;
        if (sum+bs+t[bal-1]>=0) {
            jo=1;
            bal--, bs+=t[bal];
        }
        if (sum+js+t[jobb+1]>=0) {
            jo=1;
            jobb++, js+=t[jobb];
        }
        if (bs>0) {
            jo=1;
            sum+=bs, bs=0;
        }
        if (js>0) {
            jo=1;
            sum+=js, js=0;
        }
        if (!jo || bal==0 || jobb==n+1) {
            break;
        }
    }
    cout << ((bal==0 || jobb==n+1) ? "YES" : "NO") << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
7 4
-1 -2 -3 6 -2 -3 -1
*/