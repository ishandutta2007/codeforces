#include <bits/stdc++.h>

using namespace std;
const int c=105;
int n, db[c][c], lep[c*c][c], cnt;
int kov(int a) {
    return (a==n ? 1 : a+1);
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int x;
            cin >> x;
            db[i][x]++;
        }
    }
    while (true) {
        int pos=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (db[i][j]>1) {
                    pos=i;
                }
            }
        }
        if (!pos) {
            break;
        }
        cnt++;
        int el=0;
        for (int i=pos; i<=n; i++) {
            int ert=el;
            for (int j=1; j<=n; j++) {
                if (db[i][j]>1) {
                    ert=j;
                }
            }
            lep[cnt][i]=ert;
            el=ert;
        }
        for (int i=1; i<pos; i++) {
            int ert=el;
            for (int j=1; j<=n; j++) {
                if (db[i][j]>1) {
                    ert=j;
                }
            }
            lep[cnt][i]=ert;
            el=ert;
        }
        for (int i=1; i<=n; i++) {
            int x=lep[cnt][i];
            db[i][x]--;
            db[kov(i)][x]++;
        }
    }
    for (int dif=n-1; dif>=1; dif--) {
        for (int s=1; s<=n-dif; s++) {
            cnt++;
            for (int i=1; i<=n; i++) {
                lep[cnt][i]=(i+dif<=n ? i+dif : i+dif-n);
            }
        }
    }

    cout << cnt << "\n";
    for (int i=1; i<=cnt; i++) {
        for (int j=1; j<=n; j++) {
            cout << lep[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
4
1 1 1 1
2 2 2 2
3 3 3 3
4 4 4 4
*/