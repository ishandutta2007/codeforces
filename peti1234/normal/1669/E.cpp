#include <bits/stdc++.h>

using namespace std;
long long w, db[11][11];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        long long ans=0;
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;
            db[s[0]-'a'][s[1]-'a']++;
        }
        for (int i=0; i<11; i++) {
            for (int j=0; j<11; j++) {
                for (int k=0; k<11; k++) {
                    if (k>i) ans+=db[i][j]*db[k][j];
                    if (k>j) ans+=db[i][j]*db[i][k];
                }
            }
        }
        cout << ans << "\n";
        for (int i=0; i<11; i++) {
            for (int j=0; j<11; j++) {
                db[i][j]=0;
            }
        }
    }
    return 0;
}