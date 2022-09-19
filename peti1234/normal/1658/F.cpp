#include <bits/stdc++.h>

using namespace std;
int w;
long long n, k, db, cel;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k >> s;
        db=0;
        for (int i=0; i<n; i++) if (s[i]=='1') db++;
        cel=k*db/n;
        if (cel*n!=k*db) {
            cout << -1 << "\n";
            continue;
        }
        int cnt=0;
        for (int i=0; i<k; i++) if (s[i]=='1') cnt++;
        for (int i=k; i<k+n; i++) {
            //cout << "fontos " <<cnt << " " << cel << "\n";
            if (cnt==cel) {
                if (i<=n) {
                    cout << 1 << "\n" << i-k+1 << " " << i << "\n";
                } else {
                    cout << 2 << "\n" << 1 << " " << i-n << "\n" << i-k+1 << " " << n << "\n";
                }
                break;
            }
            int el=s[i-k];
            if (el=='1') cnt--;
            if (s[i%n]=='1') cnt++;
        }
    }
    return 0;
}
/*
1
8 6
11000011
*/