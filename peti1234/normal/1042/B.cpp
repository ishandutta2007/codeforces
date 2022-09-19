#include <bits/stdc++.h>

using namespace std;
int n, ert[8], p;
int main()
{
    for (int i=0; i<8; i++) ert[i]=1e7;
    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        int a, b=0;
        cin >> a >> s;
        for (auto x:s) {
            if (x=='A') b=b+1;
            if (x=='B') b=b+2;
            if (x=='C') b=b+4;
        }
        p=(p|b);
        ert[b]=min(ert[b], a);
    }
    if (p!=7) {
        cout << -1 << "\n";
    } else {
        for (int i=0; i<7; i++) {
            for (int j=0; j<7; j++) {
                if ((i & j)==j) {
                    ert[j]=min(ert[i], ert[j]);
                }
            }
        }
        cout << min({ert[1]+ert[2]+ert[4], ert[3]+ert[4], ert[5]+ert[2], ert[6]+ert[1], ert[7]}) << "\n";
    }
    return 0;
}