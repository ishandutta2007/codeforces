#include <bits/stdc++.h>

using namespace std;
int w;
long long n;
bool v[52][52], jo=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, jo=1;
        for (int i=1; i<=n; i++) v[i][n+1]=1, v[n+1][i]=1;
        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) {
            char c; cin >> c; v[i][j]=c=='1';
        }
        for (int i=n; i>=1; i--) for (int j=n; j>=1; j--) if (v[i][j] && !v[i+1][j] && !v[i][j+1]) jo=false;
        if (jo) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}