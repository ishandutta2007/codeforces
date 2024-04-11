#include <bits/stdc++.h>

using namespace std;
bool v[55][55];
int main()
{
    int w;
    cin >> w;
    while (w--) {
        memset(v, 0, sizeof(v));
        int n, m;
        cin >> n >> m;
        bool jo=1;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char c;
                cin >> c;
                v[i][j]=(c=='*');
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (!v[i][j]) continue;
                int db=0;
                int a, b, c, d;
                for (int ii=i-1; ii<=i+1; ii++) {
                    for (int jj=j-1; jj<=j+1; jj++) {
                        if (ii==i && jj==j) continue;
                        if (v[ii][jj]) {
                            db++;
                            if (db==1) a=ii, b=jj;
                            else c=ii, d=jj;
                        }
                    }
                }
                if (db!=2) {
                    jo=0;
                } else {
                    if (abs(a-c)>1 || abs(b-d)>1) {
                        jo=0;
                    }
                }
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}