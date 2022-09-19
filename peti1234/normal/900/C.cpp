#include <bits/stdc++.h>

using namespace std;
int n, s1, s2, ert, t[100002], ans[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        t[i]=x;
        if (x>s2 && x<s1) {
            ans[s1]++;
            s2=x;
        }
        if (x>s1) {
            ans[x]--;
            s2=s1;
            s1=x;
        }
    }
    ert=t[1];
    for (int i=1; i<=n; i++) {
        if (ans[t[i]]>ans[ert] || (ans[t[i]]==ans[ert] && t[i]<ert)) {
            ert=t[i];
        }
    }
    cout << ert << "\n";
    return 0;
}