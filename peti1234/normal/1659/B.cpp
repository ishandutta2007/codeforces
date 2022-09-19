#include <bits/stdc++.h>

using namespace std;
int w, n, k, ert, res[200005];
string s, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k >> s;
        ert=k;
        for (int i=0; i<n; i++) {
            if (i==n-1) {
                res[i]=ert;
            }
            else if (ert && (s[i]=='1' && k%2 || s[i]=='0' && k%2==0)) {
                res[i]=1;
                ert--;
            }
            if (s[i]=='0' && (k-res[i])%2 || s[i]=='1' && (k-res[i])%2==0) {
                ans+="1";
            } else {
                ans+="0";
            }
        }
        cout << ans << "\n";
        for (int i=0; i<n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";

        ans.clear();
        for (int i=0; i<n; i++) {
            res[i]=0;
        }

    }
    return 0;
}