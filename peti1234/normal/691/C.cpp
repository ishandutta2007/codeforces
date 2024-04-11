#include <bits/stdc++.h>

using namespace std;
string s;
int n, kezd, veg, db=-1, f;
int main()
{
    cin >> s;
    n=s.size(), kezd=0, veg=n-1;
    bool g=0;
    for (int i=0; i<n; i++) {
        if (s[i]=='.') g=1;
    }
    if (!g) {
        s+=".";
        n++, veg++;
    }
    while (s[kezd]=='0') kezd++;
    while (s[veg]=='0') veg--;
    for (int i=kezd; i<=veg; i++) {
        if (s[i]!='.') db++;
        else break;
    }
    if (s[veg]=='.') {
        veg--;
        while (s[veg]=='0') {
            s.pop_back();
            veg--;
        }
    }
    if (s[kezd]=='.') {
        db=0;
        while (s[kezd]=='.' || s[kezd]=='0') db--, kezd++;
    }
    for (int i=kezd; i<=veg; i++) {
        if (s[i]!='.') {
            if (f==1) cout << '.';
            cout << s[i];
            f++;
        }
    }
    if (db!=0) {
        cout << 'E';
        cout << db << "\n";
    }
    return 0;
}