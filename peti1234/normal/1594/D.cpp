#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int w, n, m, si[c], ki[c];
int holvan(int a) {
    return (!ki[a] ? a : ki[a]=holvan(ki[a]));
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        si[a]+=si[b];
        si[b]=0;
        ki[b]=a;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            si[i]=0, ki[i]=0;
        }
        for (int i=n+1; i<=2*n; i++) {
            si[i]=1, ki[i]=0;
        }
        for (int i=1; i<=m; i++) {
            int a, b;
            string s;
            cin >> a >> b >> s;
            if (s=="crewmate") {
                unio(a, b);
                unio(a+n, b+n);
            } else {
                unio(a, b+n);
                unio(a+n, b);
            }
        }
        bool baj=0;
        int ans=0;
        for (int i=1; i<=n; i++) {
            int a=holvan(i), b=holvan(i+n);
            if (a==b) {
                baj=1;
            }
            if (a==i != b==i+n && !baj) {
                cout << "rossz\n";
                exit(0);
            }
            if (a==i) {
                ans+=max(si[a], si[b]);
            }
        }
        if (baj) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
/*
1
3 2
1 2 imposter
2 3 crewmate
*/