#include <bits/stdc++.h>

using namespace std;
string s, s2;
int q, l, r, k;
int main()
{
    cin >> s >> q;
    while (q--) {
        cin >> l >> r >> k;
        s2=s;
        l--, r--;
        for (int i=l; i<=r; i++) {
            int kov=l+(i-l+k)%(r-l+1);
            s[kov]=s2[i];
        }
    }
    cout << s << "\n";
    return 0;
}