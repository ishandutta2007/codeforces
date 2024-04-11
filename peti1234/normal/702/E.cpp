#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=34;
long long n, m, kov[c][k], sum[c][k], mini[c][k];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        kov[i][0]=x;
    }
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sum[i][0]=x, mini[i][0]=x;
    }
    for (int j=1; j<k; j++) {
        for (int i=0; i<n; i++) {
            int s=kov[i][j-1];
            kov[i][j]=kov[s][j-1];
            sum[i][j]=sum[i][j-1]+sum[s][j-1];
            mini[i][j]=min(mini[i][j-1], mini[s][j-1]);
        }
    }
    for (int i=0; i<n; i++) {
        long long po=1;
        long long pos=i, s2=0, m2=1e12;
        for (int j=0; j<k; j++) {
            if (m & po) {
                s2+=sum[pos][j];
                m2=min(m2, mini[pos][j]);
                pos=kov[pos][j];
            }
            po*=2;
        }
        cout << s2 << " " << m2 << "\n";
    }
    return 0;
}