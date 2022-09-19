#include <bits/stdc++.h>

using namespace std;
int db[26];
string s, ans;
int main()
{
    cin >> s;
    for (auto x:s) {
        int k=x-'a';
        db[k]++;
    }
    for (int i=0; i<26; i++) {
        for (int j=25; j>i; j--) {
            if (db[i]%2 && db[j]%2) {
                db[i]++, db[j]--;
            }
        }
    }
    for (int i=0; i<26; i++) {
        while (db[i]>1) {
            char c='a'+i;
            ans.push_back(c);
            db[i]-=2;
        }
    }
    cout << ans;
    for (int i=0; i<26; i++) {
        if (db[i]) {
            char c='a'+i;
            cout << c;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}