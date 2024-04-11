#include <bits/stdc++.h>

using namespace std;
const int c=200005, k=20;
long long n, m, sum, pos, ert, t[c], kov[c][k];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> ert;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    t[n+1]=ert+1;
    for (int i=1; i<=n+1; i++) {
        while (sum<=ert) {
            pos++;
            sum+=t[pos];
        }
        kov[i][0]=pos;
        sum-=t[i];
    }
    for (int j=1; j<k; j++) {
        for (int i=1; i<=n+1; i++) {
            kov[i][j]=kov[kov[i][j-1]][j-1];
        }
    }
    for (int i=1; i<=n; i++) {
        int pos=i;
        for (int j=0; j<k; j++) {
            if (m & (1<<j)) {
                pos=kov[pos][j];
            }
        }
        if (pos==n+1) {
            cout << pos-i << "\n";
            return 0;
        }
    }
    return 0;
}