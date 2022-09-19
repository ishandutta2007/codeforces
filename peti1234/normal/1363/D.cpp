#include <bits/stdc++.h>

using namespace std;
int w, n, k, maxi, pos, ert;
int t[1002];
int kerd(int a, int b) {
    int cnt=0;
    for (int i=1; i<=n; i++) if (t[i]>b || t[i]<a) cnt++;
    cout << "? " << cnt << " ";
    for (int i=1; i<=n; i++) if (t[i]>b || t[i]<a) cout << i << " ";
    cout.flush() << "\n";
    int x;
    cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) t[i]=0;
        for (int i=1; i<=k; i++) {
            int x;
            cin >> x;
            for (int j=1; j<=x; j++) {
                int a; cin >> a;
                t[a]=i;
            }
        }
        maxi=kerd(k+1, k+1);
        int x=1, y=k+1;
        while(y-x>1) {
            int z=(x+y)/2;
            if (kerd(x, z-1)==maxi) x=z;
            else y=z;
        }
        pos=x;
        ert=kerd(pos, pos);
        cout << "! ";
        for (int i=1; i<=k; i++) {
            if (i!=pos) cout << maxi << " ";
            else cout << ert << " ";
        }
        cout.flush() << "\n";
        string s;
        cin >> s;
    }
    return 0;
}