#include <bits/stdc++.h>

using namespace std;
int n, k, ert[100005];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n >> s;
        for (int i=0; i<=n; i++) {
            ert[i]=-1e9;
        }
        cin >> k;
        int maxi=0;
        for (int i=1; i<=k; i++) {
            char c;
            cin >> c;
            for (int j=0; j<n; j++) {
                if (s[j]==c) {
                    ert[j]=1;
                    if (j>0) maxi=1;
                }
            }
        }
        for (int i=n-1; i>=1; i--) {
            if (ert[i]!=1) {
                ert[i]=ert[i+1]+1;
                maxi=max(maxi, ert[i]);
            }
        }
        //cout << "valasz................. ";
        cout << maxi << "\n";
    }
    return 0;
}
/*
1
5
zondl
5 a b c e f
*/