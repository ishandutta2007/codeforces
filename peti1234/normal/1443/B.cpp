#include <bits/stdc++.h>

using namespace std;
int w, n, a, b, sum, db;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b, sum=0, db=1e4;
        cin >> s, n=s.size();
        for (int i=0; i<n; i++) {
            if (s[i]=='0') db++;
            else {
                sum+=min(db*b, a);
                db=0;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}