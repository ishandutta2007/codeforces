#include <bits/stdc++.h>

using namespace std;
int w;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        int n, db=0, pos=0, ut=-1;
        string s;
        cin >> n >> s;
        db=0, pos=0;
        while (pos<n) {
            if (s[pos]=='(' && pos+1<n) {
                db++;
                pos+=2;
                ut=pos-1;
            } else {
                pos++;
                while (pos<n && s[pos]=='(') {
                    pos++;
                }
                if (pos<n) {
                    db++;
                    ut=pos;
                    pos++;
                }
            }
        }
        cout << db << " " << n-ut-1 << "\n";
    }
    return 0;
}