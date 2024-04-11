#include <bits/stdc++.h>

using namespace std;
int q, si, bsi;
int t[27], nn;
string a, b;
void valt(int x, int y) {
    if (!t[x]) nn++;
    t[x]+=y;
    if (!t[x]) nn--;
}
int main()
{
    cin >> q;
    while(q--) {
        cin >> a >> b;
        for (int i=0; i<=26; i++) t[i]=0;
        si=a.size(), bsi=b.size(), nn=0;
        for (int i=0; i<si; i++) {
            int x=a[i]-'a'+1;
            valt(x, 1);
        }
        if (si>bsi) {
            cout << "NO" << "\n";
            continue;
        }
        for (int i=0; i<si; i++) {
            int x=b[i]-'a'+1;
            valt(x, -1);
        }
        bool v=false;
        if (!nn) v=true;
        for (int i=si; i<bsi; i++) {
            int x=b[i]-'a'+1;
            valt(x, -1);
            x=b[i-si]-'a'+1;
            valt(x, 1);
            if (!nn) v=true;
        }
        if (v) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}