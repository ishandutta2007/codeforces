#include <bits/stdc++.h>

using namespace std;
const int c=100002, k=26;
int w, n, m, kov[c][k], ut[k];
string s, z;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s >> z;
        n=s.size(), m=z.size();
        for (int i=0; i<k; i++) {
            ut[i]=0;
            for (int j=0; j<=n; j++) {
                kov[j][i]=0;
            }
        }
        for (int i=1; i<=n; i++) {
            int x=(s[i-1]-'a');
            for (int j=ut[x]; j<i; j++) {
                kov[j][x]=i;
            }
            ut[x]=i;
        }
        int pos=0, ans=1;
        for (int i=0; i<m; i++) {
            int x=(z[i]-'a');
            if (!kov[pos][x]) {
                pos=0, ans++;
            }
            if (!kov[pos][x]) {
                ans=-1;
                break;
            }
            pos=kov[pos][x];
        }
        cout << ans << "\n";
    }
    return 0;
}