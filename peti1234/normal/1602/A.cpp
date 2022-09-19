#include <bits/stdc++.h>

using namespace std;
int w, pos;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        pos=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]<s[pos]) {
                pos=i;
            }
        }
        cout << s[pos] << " ";
        for (int i=0; i<s.size(); i++) {
            if (i!=pos) {
                cout << s[i];
            }
        }
        cout << "\n";
    }
    return 0;
}