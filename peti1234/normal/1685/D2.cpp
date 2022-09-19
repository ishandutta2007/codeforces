#include <bits/stdc++.h>

using namespace std;
const int c=205;
int w, n, t[c], ans[c], ki[c], fel[c], le[c];
bool fix[c];
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
bool unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
        return true;
    }
    return false;
}
bool jo(int p) {
    for (int i=1; i<p; i++) {
        if (ans[i]==ans[p]) {
            return false;
        }
    }
    for (int i=1; i<=n; i++) {
        fel[i]=0, le[i]=0, ki[i]=0, fix[i]=0;
    }
    for (int i=1; i<=n; i++) {
        unio(i, t[i]);
    }
    for (int i=2; i<=p; i++) {
        int regi=t[ans[i]], uj=ans[i-1], dif=(abs(regi-uj)==1 ? 1 : 2);
        if (regi<uj) {
            for (int j=regi; j<uj; j++) {
                fel[j]+=dif;
            }
        } else if (regi>uj) {
            for (int j=regi-1; j>=uj; j--) {
                le[j]+=dif;
            }
        } else {
            fix[regi]=1;
        }
    }
    for (int i=1; i<n; i++) {
        if (fel[i]>2 || le[i]>2 || (fix[i+1] && (fel[i] || le[i])) || (fel[i]==2 && fel[i+1]==2 && le[i]==2 && le[i+1]==2)) {
            return false;
        }
        if (fel[i] || le[i]) {
            if (!unio(i, i+1)) {
                return false;
            }
        }
        if (fel[i] && le[i]) {
            fix[i]=1, fix[i+1]=1;
        }
    }
    for (int i=1; i<n; i++) {
        if (!fix[i] && !fix[i+1]) {
            unio(i, i+1);
        }
    }
    for (int i=2; i<=n; i++) {
        if (unio(1, i)) {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        ans[1]=1;
        for (int i=2; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                ans[i]=j;
                if (jo(i)) {
                    break;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";

        for (int i=1; i<=n; i++) {
            t[i]=0, ans[i]=0;
        }
    }
    return 0;
}