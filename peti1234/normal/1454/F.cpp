#include <bits/stdc++.h>

using namespace std;
const int c=2e5+2, k=20;
int w, n, t[c], mini[c][k], emax[c], hmax[c], lg[c];
bool jo=0;
void proba(int bal, int jobb) {
    if (jobb-bal>1) {
        int ert=lg[jobb-bal-1], koz=min(mini[bal+1][ert], mini[jobb-(1<<ert)][ert]);
        if (!jo && emax[bal]==hmax[jobb] && emax[bal]==koz) {
        jo=1;
        cout << "YES\n" << bal << " " << jobb-bal-1 << " " << n-jobb+1 << "\n";
        }
    }
}
int main()
{
    for (int i=2; i<c; i++) lg[i]=lg[i/2]+1;
    cin >> w;
    for (int i=1; i<=w; i++) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            mini[i][0]=t[i], emax[i]=t[i], hmax[i]=t[i];
        }
        for (int j=1; j<k; j++) {
            int s=(1<<j);
            for (int i=1; i+s<=n+1; i++) {
                mini[i][j]=min(mini[i][j-1], mini[i+s/2][j-1]);
            }
        }
        for (int i=2; i<=n; i++) emax[i]=max(emax[i], emax[i-1]), hmax[n+1-i]=max(hmax[n+1-i], hmax[n+2-i]);
        jo=0;
        int bal=1, jobb=n;
        while(bal<jobb) {
            while(emax[bal]<hmax[jobb] || (bal<n && emax[bal]>t[bal+1]) || (bal+1<n && emax[bal]==t[bal+1] && emax[bal]>=t[bal+2])) {
                proba(bal, jobb), bal++;
            }
            proba(bal, jobb);

            jobb--;
        }
        for (int i=1; i<=n-2; i++) proba(i, i+2);
        if (!jo) {
            cout << "NO\n";
        }
    }
    return 0;
}
/*
1
11
1 2 3 3 3 4 4 3 4 2 1
*/