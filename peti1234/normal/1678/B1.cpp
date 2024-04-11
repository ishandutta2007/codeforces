#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        int valt=0, db=1;
        for (int i=1; i<n; i+=2) {
            if (s[i]!=s[i-1]) {
                valt++;
                if (i==1 || s[i-1]!=s[i-2]) s[i-1]=s[i];
                else s[i]=s[i-1];
            }
        }
        for (int i=2; i<n; i+=2) {
            if (s[i]!=s[i-1]) db++;
        }
        cout << valt << "\n";
    }
    return 0;
}