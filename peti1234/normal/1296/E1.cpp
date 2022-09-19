#include <bits/stdc++.h>

using namespace std;
int n;
string s, ans;
char a='a', b='a';
bool baj;
int main()
{
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        if (s[i]<a) {
            baj=1;
        }
        if (s[i]>=b) {
            ans+='1';
            b=s[i];
        } else {
            ans+='0';
            a=s[i];
        }
    }
    if (baj) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << ans << "\n";
    }
    return 0;
}