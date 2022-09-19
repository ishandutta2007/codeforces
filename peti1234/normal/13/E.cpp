#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=400;
int n, q, t[c], kov[c], db[c];
void calc(int a) {
    int s=(a+t[a]);
    if (s<=n && a/k==s/k) {
        kov[a]=kov[s];
        db[a]=db[s]+1;
    } else {
        kov[a]=a;
        db[a]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=n; i>=1; i--) {
        calc(i);
    }
    for (int i=1; i<=q; i++) {
        int id;
        cin >> id;
        if (id==0) {
            int a, b;
            cin >> a >> b;
            t[a]=b;
            for (int i=a; i>=a/k*k; i--) {
                calc(i);
            }
        } else {
            int x, cnt=0;
            cin >> x;
            while (x+t[x]<=n) {
                if (kov[x]>x) {
                    cnt+=db[x];
                    x=kov[x];
                } else {
                    cnt++;
                    x+=t[x];
                }
            }
            cout << x << " " << cnt+1 << "\n";
        }
    }
    return 0;
}