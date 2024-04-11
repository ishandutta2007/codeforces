#include <bits/stdc++.h>

using namespace std;
const int c=505;
int n, m, k, e, baj;
bool v[c][c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            v[i][j]=(c=='*');
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (v[i][j]) {
                bool a=v[i-1][j], b=v[i+1][j], c=v[i][j-1], d=v[i][j+1];
                int s=a+b+c+d;
                if (s==4) {
                    k++;
                }
                if (s==3 || s==0) {
                    baj=1;
                }
                if (s==2 && a!=b) {
                    baj=1;
                }
                if (s==1) {
                    e++;
                }
            }
        }
    }
    cout << (!baj && k==1 && e==4 ? "YES" : "NO") << "\n";
    return 0;
}