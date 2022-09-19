#include <bits/stdc++.h>

using namespace std;
const int c=200005;
vector<int> s={0, 1, 2};
int n, q, t[c][3][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        int a=i%3, b=(c-'a');
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                t[i][j][k]=t[i-1][j][k];
            }
        }
        t[i][a][b]++;
    }
    for (int tc=1; tc<=q; tc++) {
        int l, r;
        cin >> l >> r;
        int maxi=0;
        do {
            int db=0;
            for (int i=0; i<3; i++) {
                db+=t[r][i][s[i]]-t[l-1][i][s[i]];
            }
            maxi=max(maxi, db);
        } while (next_permutation(s.begin(), s.end()));
        cout << r-l+1-maxi << "\n";
    }
    return 0;
}