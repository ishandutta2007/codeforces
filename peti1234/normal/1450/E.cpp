#include <bits/stdc++.h>

using namespace std;
const int c=202;
int el[c][c], n, m, pos, maxi, baj, ki[2*c];
int holvan(int a) {
    if (!ki[a]) return a;
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
int unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, x; cin >> a >> b >> x;
        unio(a, b+n), unio(b, a+n);
        el[b][a]=1;
        if (x==0) el[a][b]=1;
        else el[a][b]=-1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) if (i!=j && !el[i][j]) el[i][j]=c;
    }
    /*
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << el[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                el[i][j]=min(el[i][j], el[i][k]+el[k][j]);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (holvan(i)==holvan(i+n)) {
            baj=1;
        }
        if (el[i][i]<0) {
            baj=1;
        }
    }
    if (baj) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (el[i][j]>maxi) {
                maxi=el[i][j];
                pos=i, maxi=el[i][j];
            }
        }
    }
    cout << maxi << "\n";
    for (int i=1; i<=n; i++) {
        cout << maxi-el[pos][i] << " ";
    }
    cout << "\n";
    // minimlis t mindnehonnan mindenhova
    // nincs megolds, ha tav[a][a]<0
    // megolds az tav[i][j]-k maximuma
    return 0;
}