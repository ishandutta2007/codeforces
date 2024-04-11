#include <bits/stdc++.h>

using namespace std;
int w, n, t[5], db[5], rossz[5][5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=0; i<5; i++) {
            db[i]=0;
            for (int j=0; j<5; j++) {
                rossz[i][j]=0;
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<5; j++) {
                cin >> t[j];
                db[j]+=t[j];
            }
            for (int a=0; a<5; a++) {
                for (int b=0; b<5; b++) {
                    if (t[a]==0 && t[b]==0) {
                        rossz[a][b]=1;
                    }
                }
            }
        }
        bool jo=0;
        for (int a=0; a<5; a++) {
            for (int b=a+1; b<5; b++) {
                if (2*db[a]>=n && 2*db[b]>=n && !rossz[a][b]) {
                    jo=1;
                }
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}