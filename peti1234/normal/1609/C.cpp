#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
bool pr[c];
long long w, n, k, t[c], bal[c], jobb[c], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=2; i<c; i++) {
        if (!pr[i]) {
            for (int j=2*i; j<c; j+=i) {
                pr[j]=1;
            }
        }
    }
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            if (!pr[t[i]] && i>k && t[i-k]==1) {
                bal[i]=bal[i-k]+1;
            }
        }
        for (int i=n; i>=1; i--) {
            if (!pr[t[i]] && i+k<=n && t[i+k]==1) {
                jobb[i]=jobb[i+k]+1;
            }
        }
        for (int i=1; i<=n; i++) {
            if (t[i]>1 && !pr[t[i]]) {
                ans=ans+(bal[i]+1)*(jobb[i]+1)-1;
            }
        }
        //cout << "valasz................. ";
        cout << ans << "\n";
        for (int i=1; i<=n; i++) bal[i]=0, jobb[i]=0;
        ans=0;
    }
    return 0;
}
/*
1
7 3
10 2 1 3 1 19 3
*/