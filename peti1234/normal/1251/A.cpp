#include <bits/stdc++.h>

using namespace std;
const int c=26;
int w, n, h;
string s;
bool jo[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size(), h=1;
        for (int i=1; i<n; i++) {
            if (s[i]!=s[i-1]) {
                if (h%2) {
                    jo[s[i-1]-'a']=1;
                }
                h=0;
            }
            h++;
        }
        if (h%2) {
            jo[s[n-1]-'a']=1;
        }
        char f='a';
        for (int i=0; i<c; i++) {
            if (jo[i]) {
                cout << f;
            }
            f++;
            jo[i]=0;
        }
        cout << "\n";
    }
    return 0;
}