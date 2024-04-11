#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, m, q, cnt, t[c], fen[c];
int lsb(int a) {
    return (a & -a);
}
void add(int a, int b) {
    //cout << "add " << a << " " << b << "\n";
    while (a<=n*m) {
        fen[a]+=b;
        a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=fen[a];
        a-=lsb(a);
    }
    return ans;
}
void valt(int a) {
    int s=(t[a] ? -1 : 1);
    add(a, s);
    t[a]+=s;
    cnt+=s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int s=(j-1)*n+i;
            char c;
            cin >> c;
            if (c=='*') {
                valt(s);
            }
        }
    }
    for (int i=1; i<=q; i++) {
        int a, b, s;
        cin >> a >> b;
        s=(b-1)*n+a;
        valt(s);
        cout << cnt-ask(cnt) << "\n";
    }
    return 0;
}