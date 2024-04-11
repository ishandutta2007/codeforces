#include <bits/stdc++.h>

using namespace std;
const long long c=2000005, sok=1e9, o=0;
int n, kov[c], el[c], t[c], mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        t[i]=x;
        kov[x]=x;
        el[x]=x;
    }
    mini=t[1];
    /*for (int i=0; i<=10; i++) {
        bool jo=1;
        for (int j=1; j<=n; j++) {
            long long ert=t[j]+i, s=sqrt(ert), kov=2*ert-s*s, s2=sqrt(kov);
            if (s!=s2) {
                jo=0;
            }
        }
        if (jo) {
            cout << i << "\n";
            return 0;
        }
    }*/
    el[0]=-sok, kov[c-1]=sok;
    for (int i=1; i<c; i++) {
        if (!el[i]) {
            el[i]=el[i-1];
        }
    }
    for (int i=c-2; i>=0; i--) {
        if (!kov[i]) {
            kov[i]=kov[i+1];
        }
    }
    for (long long ert=1; ; ert++) {
        if (ert*(ert+1)<mini) continue;
        long long kis=max(o, mini-ert*ert), nagy=ert, pos=mini, val=ert;
        if (ert==1) {
            //cout << kis << " " << nagy << "\n";
        }
        while (pos<c) {
            pos+=val;
            nagy=min(nagy, pos-el[min(pos, c-1)]);
            if (ert==1) {
                //cout << "nagy " << pos << " " << el[pos] << "\n";
            }
            pos++;
            if (pos<c) {
                kis=max(kis, pos+val-kov[pos]);
            }
            pos+=val;
            val++;

        }
        if (ert==1) {
            //cout << "fontos " << kis << " " << nagy << "\n";
        }
        if (kis<=nagy) {
            cout << ert*ert-mini+kis << "\n";
            return 0;
        }
    }
    return 0;
}
/*
4
1 3 8 10
*/
/*
6
5
16
29
44
61
80
*/