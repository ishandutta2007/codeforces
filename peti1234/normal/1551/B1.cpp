#include <bits/stdc++.h>

using namespace std;
int w, n, db[26], cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cnt=0;
        for (int i=0; i<26; i++) {
            db[i]=0;
        }
        string s;
        cin >> s;
        n=s.size();
        for (int i=0; i<n; i++) {
            char c=s[i];;
            if (db[c-'a']<2) {
                db[c-'a']++;
                cnt++;
            }
        }
        cout << cnt/2 << "\n";
    }
    return 0;
}