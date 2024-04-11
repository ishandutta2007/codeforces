#include <bits/stdc++.h>

using namespace std;
const int c=(1<<19);
int k, n, q, db[c], valt[c], t[c];
string s;
void calc(int ert) {
    db[ert]=0;
    if (t[ert]%2) {
        db[ert]+=db[2*ert];
    }
    if (t[ert]%4>=2) {
        db[ert]+=db[2*ert+1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> k;
    n=(1<<k);
    for (int i=n; i<2*n; i++) {
        db[i]=1;
    }
    int pos=0;
    valt[0]=n/2;
    for (int i=1; i<n-1; i++) {
        valt[i]=valt[pos]+i-pos;
        if (i==pos+valt[pos]) {
            valt[i]=valt[pos]/2;
            pos=i;
        }
    }
    for (int i=0; i<n-1; i++) {
        char c;
        cin >> c;
        int ert=valt[i];
        if (c=='0') {
            t[ert]=1;
        }
        if (c=='1') {
            t[ert]=2;
        }
        if (c=='?') {
            t[ert]=3;
        }
        //cout << "calc " << ert << "\n";
        calc(ert);
        //cout << db[ert] << "\n";
    }
    cin >> q;
    while (q--) {
        int ert;
        char c;
        cin >> ert >> c;
        ert=valt[ert-1];
        if (c=='0') {
            t[ert]=1;
        }
        if (c=='1') {
            t[ert]=2;
        }
        if (c=='?') {
            t[ert]=3;
        }
        calc(ert);
        while (ert>1) {
            ert/=2;
            calc(ert);
        }
        cout << db[1] << "\n";
    }
    return 0;
}
/*
3
0110?11
0
*/