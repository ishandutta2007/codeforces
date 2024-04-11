#include <bits/stdc++.h>

using namespace std;
int w, n, k, ut, db;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, ut=-k-1, db=0;
        cin >> s;
        for (int i=0; i<n; i++) {
            if (s[i]=='0' && i-ut>k) db++, ut=i;
            if (s[i]=='1') {
                if (i-ut<=k) db--;
                ut=i;
            }
        }
        cout << db << "\n";
    }
    return 0;
}