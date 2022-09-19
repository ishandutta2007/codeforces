#include <bits/stdc++.h>

using namespace std;
const int c=10000002;
int sqf[c], db[c];
int w, n, k, t[200002];
int main()
{
    for (int i=1; i<c; i++) {
        sqf[i]=i;
    }
    for (int i=2; i*i<c; i++) {
        int ert=i*i;
        for (int j=ert; j<c; j+=ert) {
            while (sqf[j]%ert==0) {
                sqf[j]/=ert;
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        int pos=1, sum=1;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            t[i]=sqf[t[i]];
            if (db[t[i]]) {
                sum++;
                for (int j=pos; j<i; j++) {
                    db[t[j]]--;
                }
                pos=i;
            }
            db[t[i]]++;
        }
        for (int i=pos; i<=n; i++) {
            db[sqf[t[i]]]--;
        }
        cout << sum << "\n";
    }
    return 0;
}
/*
1
5 0
18 6 2 4 1
*/