#include <bits/stdc++.h>

using namespace std;
int w, t[101][101];
void out(int a)
{
    a--;
    if (a<10) {
        cout << a;
        return;
    }
    a-=10;
    if (a<26) {
        char c='a';
        c+=a;
        cout << c;
        return;
    }
    a-=26;
    char c='A';
    c+=a;
    cout << c;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        int n, m, k;
        int sum=0;
        cin >> n >> m >> k;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char c;
                cin >> c;
                t[i][j]=(c=='R');
                sum+=t[i][j];
            }
        }
        int db=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                int s=j;
                if (i%2) {
                    s=m+1-j;
                }
                if (t[i][s]) {
                    db++;
                }
                if (db*k>sum) {
                    sum-=db;
                    k--;
                    db=0;
                }
                t[i][s]=k;
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                out(t[i][j]);
            }
            cout << "\n";
        }
    }
    return 0;
}