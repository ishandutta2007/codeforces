#include <bits/stdc++.h>

using namespace std;
const int c=8505;
int w, n, t[c], inv[c], ans[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> inv[i];
            t[inv[i]]=i;
        }
        for (int ert=1; ert<=24; ert++) {
            for (int p=n; p>=1; p--) {
                int pos=inv[p];
                if (!ans[pos]) {
                    ans[pos]=ert;
                    int p2=pos-1;
                    while (p2>=1 && (t[p2]>p || ans[p2]>0)) {
                        p2--;
                    }
                    if (p2>=1) {
                        ans[p2]=-1;
                    }
                    p2=pos+1;
                    while (p2<=n && (t[p2]>p || ans[p2]>0)) {
                        p2++;
                    }
                    if (p2<=n) {
                        ans[p2]=-1;
                    }
                }
            }
            for (int i=1; i<=n; i++) {
                if (ans[i]==-1) {
                    ans[i]=0;
                }
            }
        }

        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        for (int i=1; i<=n; i++) {
            t[i]=0, inv[i]=0, ans[i]=0;
        }
    }
    return 0;
}
/*
1
10
6 10 4 2 7 9 5 8 3 1
*/