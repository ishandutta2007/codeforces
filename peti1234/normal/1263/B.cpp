#include <bits/stdc++.h>

using namespace std;
int t[11];
int db, n;
void fix(int a)
{
    for (int i=1; i<=n; i++) {
        if (i!=a && t[i]==t[a]) {
            t[a]+=1000;
            fix(a);
        }
    }
}
int cnt(int a)
{
    if (a==0) {
        return 1;
    }
    int ans=0;
    for (int i=1; a>0; i++) {
        a/=10;
        ans++;
    }
    return ans;
}
int main()
{
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> n;
        db=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (i!=j && t[i]==t[j]) {
                    db++;
                    t[i]%=1000;
                    fix(i);
                }
            }
        }
        cout << db << "\n";
        for (int i=1; i<=n; i++) {
            int x=cnt(t[i]);
            for (int i=1; i<=4-x; i++) {
                cout << 0;
            }
            cout << t[i] << "\n";
        }
    }
    return 0;
}
/*
1
2
0000
0000
*/