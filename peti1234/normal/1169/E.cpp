#include <bits/stdc++.h>
 
using namespace std;
int n, q;
bool t[300001][21];
int kov[300001][21];
int el[300001][21];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        int x=1;
        while(a>0) {
            if (a%2!=0) {
                t[i][x]=true;
            }
            a/=2;
            x++;
        }
    }
    /*for (int i=1; i<=n; i++) {
        for (int j=1; j<=20; j++) {
            cout << t[i][j];
        }
        cout << endl;
    }*/
    int akt=0;
    for (int j=1; j<=20; j++) {
        for (int i=n; i>=1; i--) {
            if (t[i][j]) {
                kov[i][j]=akt;
                akt=i;
            }
            el[i][j]=INT_MAX;
        }
        akt=0;
    }
    /*for (int i=1; i<=n; i++) {
        cout << kov[i][1] << endl;
    }*/
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=20; j++) {
            if (t[i][j]) {
                el[i][j]=i;
                if (kov[i][j]!=0) {
                    for (int k=1; k<=20; k++) {
                        int p=kov[i][j];
                        el[i][k]=min(el[i][k], el[p][k]);
                    }
                }
            }
        }
    }
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        bool c=false;
        for (int i=1; i<=20; i++) {
            if (t[b][i] && el[a][i]<=b) {
                c=true;
            }
        }
        if (c) {
            cout << "Shi" << "\n";
        } else {
            cout << "Fou" << "\n";
        }
    }
    return 0;
}