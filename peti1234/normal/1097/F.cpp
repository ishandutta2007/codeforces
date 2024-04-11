#include <bits/stdc++.h>

using namespace std;
const int c=7001, c2=100001;
int n, q;
bitset<c> q1[c], q4[c], t[c2];
bool sq[c];
int main()
{
    for (int i=2; i<c; i++) {
        for (int j=i*i; j<c; j+=i*i) {
            sq[j]=1;
        }
    }
    for (int i=1; i<c; i++) {
        for (int j=i; j<c; j+=i) {
            q1[j][i]=1;
            if (!sq[j/i]) {
                q4[i][j]=1;
            }
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    while (q--) {
        int id, x, y, z;
        cin >> id >> x >> y;
        if (id==1) {
            t[x]=q1[y];
        }
        if (id==2) {
            cin >> z;
            t[x]=(t[y]^t[z]);
        }
        if (id==3) {
            cin >> z;
            t[x]=(t[y]&t[z]);
        }
        if (id==4) {
            cout << ((t[x]&q4[y]).count())%2;
        }
    }
    return 0;
}