#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, q, fen[c][2], sor[c], oszlop[c];
int lsb(int a) {
    return (a & -a);
}
void add(int a, int b, int id) {
    while (a<=n) {
        fen[a][id]+=b;
        a+=lsb(a);
    }
}
int ask(int a, int id) {
    int ans=0;
    while (a) {
        ans+=fen[a][id];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    while (q--) {
        int id;
        cin >> id;
        if (id<=2) {
            int a, b;
            cin >> a >> b;
            if (id==1) {
                sor[a]++;
                if (sor[a]==1) {
                    add(a, 1, 0);
                }
                oszlop[b]++;
                if (oszlop[b]==1) {
                    add(b, 1, 1);
                }
            }
            if (id==2) {
                sor[a]--;
                if (sor[a]==0) {
                    add(a, -1, 0);
                }
                oszlop[b]--;
                if (oszlop[b]==0) {
                    add(b, -1, 1);
                }
            }
        } else {
            int ks, ko, ns, no;
            cin >> ks >> ko >> ns >> no;
            int a=ask(ns, 0)-ask(ks-1, 0), b=ask(no, 1)-ask(ko-1, 1);
            cout << (a==ns-ks+1 || b==no-ko+1 ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}
/*
8 5
1 2 4
1 3 2
1 4 3
2 4 3
3 2 6 4 8
*/