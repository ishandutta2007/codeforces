#include <bits/stdc++.h>

using namespace std;
int w, n, k, maxi, db, cnt;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k >> s, db=0, maxi=0;
        for (int i=0; i<n; i++) db+=(s[i]=='1');
        for (int i=0; i<k; i++) {
            cnt=0;
            for (int j=i; j<n; j+=k) {
                if (s[j]=='1') cnt++;
                else cnt--;
                cnt=max(0, cnt), maxi=max(maxi, cnt);
            }
        }
        cout << db-maxi << "\n";
    }
    return 0;
}