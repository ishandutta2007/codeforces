#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, m;
        string s[105];
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            cin >> s[i];
        }
        int mini=1e6;
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                int sum=0;
                for (int k=0; k<m; k++) {
                    sum+=abs(s[i][k]-s[j][k]);
                }
                mini=min(mini, sum);
            }
        }
        cout << mini << "\n";
    }
    return 0;
}