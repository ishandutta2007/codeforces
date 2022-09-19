#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int ans[c], kom[c][10], n;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<=9; i++) ans[i]=i, kom[i][i]++;
    for (int i=10; i<c; i++) {
        int ert=i, pr=1;
        while(ert) {
            if (ert%10) pr*=ert%10;
            ert/=10;
        }
        ans[i]=ans[pr];
        kom[i][ans[i]]++;
    }
    for (int i=1; i<c; i++) for (int j=1; j<=9; j++) kom[i][j]+=kom[i-1][j];
    cin >> n;
    for (int i=1; i<=n; i++) {
        int l, r, p;
        cin >> l >> r >> p;
        cout << kom[r][p]-kom[l-1][p] << "\n";
    }
    return 0;
}