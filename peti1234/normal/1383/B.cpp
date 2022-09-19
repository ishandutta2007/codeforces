#include <bits/stdc++.h>

using namespace std;
int w, n, db[32], jo, e;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, jo=0, e=0;
        for (int i=0; i<31; i++) db[i]=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            for (int j=0; x>0; j++) {
                if (x%2) db[j]++;
                x/=2;
            }
        }
        for (int i=30; i>=0; i--) {
            if (!jo && db[i]%2) {
                jo=1;
                if (db[i]%4==1 || (db[i]%4==3 && n%2==0)) e=1;
            }
        }
        if (!jo) cout << "DRAW\n";
        else if (e) cout << "WIN\n";
        else cout << "LOSE\n";
    }
    return 0;
}