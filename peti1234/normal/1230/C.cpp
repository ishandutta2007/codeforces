#include <bits/stdc++.h>

using namespace std;
int n, m, mini=100;
bool v[8][8];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        v[a][b]=1, v[b][a]=1;
    }
    for (int i=1; i<=7; i++) {
        for (int j=i+1; j<=7; j++) {
            int cnt=0;
            for (int k=1; k<=7; k++) {
                if (v[i][k] && v[j][k]) cnt++;
            }
            mini=min(mini, cnt);
        }
    }
    cout << m-mini << "\n";
    return 0;
}