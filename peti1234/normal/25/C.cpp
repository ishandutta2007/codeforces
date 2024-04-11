#include <bits/stdc++.h>

using namespace std;
const int c=302, sok=1e6;
long long sum, tav[c][c], n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> tav[i][j];
        }
    }
    cin >> k;
    for (int i=1; i<=k; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        sum=0;
        tav[a][b]=min(tav[a][b], c), tav[b][a]=tav[a][b];
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                tav[i][j]=min(tav[i][j], min(tav[i][a], tav[i][b])+tav[a][b]+min(tav[a][j], tav[b][j]));
                if (i<j) {
                    sum+=tav[i][j];
                }
            }
        }
        cout << sum << " ";
    }
    return 0;
}