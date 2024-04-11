#include <bits/stdc++.h>

using namespace std;
int w, a, b, n;
string s, k="2020";
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> s, a=0, b=0;
        while(a<4 && s[a]==k[a]) a++;
        while(b<4 && s[n-b-1]==k[4-b-1]) {
            b++;
        }
        if (a+b>=4) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}