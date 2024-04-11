#include <bits/stdc++.h>

using namespace std;
int w, n, ans, t[200002], db[200002], a, b;
bool v[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) t[i]=0, db[i]=0;
        for (int i=1; i<=n; i++) cin >> t[i], db[t[i]]++;
        bool ok=true, jo=true;
        ans=1, a=0, b=0;
        if (db[1]!=2) ok=0;
        for (int i=2; i<=n; i++) {
            if (db[i]>db[i-1]) ok=false;
            if (db[i]==2) ans=i;
        }
        for (int i=1; i<=ans; i++) v[i]=0;
        for (int i=1; i<=ans; i++) {
            int x=t[i];
            if (v[x] || x>ans) jo=false;
            v[x]=true;
        }
        if (ok && jo) a=ans;
        jo=1;
        for (int i=1; i<=ans; i++) v[i]=0;
        for (int i=n-ans+1; i<=n; i++) {
            int x=t[i];
            if (v[x] || x>ans) jo=false;
            v[x]=true;
        }
        if (ok && jo) b=n-ans;
        cout << (a>0)+(b>0 && b!=a) << "\n";
        if (a) cout << a << " " << n-a << "\n";
        if (b && a!=b) cout << b << " " << n-b << "\n";
    }
    return 0;
}
// Egy megolds ktszer is szerepelhet, ezen kvl knnyen ment.