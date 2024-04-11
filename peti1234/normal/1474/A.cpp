#include <bits/stdc++.h>

using namespace std;
int w, n, el;
string s;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> s;
        el=0;
        for (int i=0; i<n; i++) {
            int x=(s[i]=='1');
            if (el==0) {
                cout << 1;
                el=x+1;
            } else if (el==2) {
                cout << 1-x;
                el=1;
            } else {
                cout << x;
                el=2*x;
            }
        }
        cout << "\n";
    }
    return 0;
}