#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        bool spec=0;
        char el='.';
        for (int i=0; i<n-2; i++) {
            string s;
            cin >> s;
            if (i>0 && s[0]!=el) {
                cout << el;
                spec=1;
            }
            cout << s[0];
            el=s[1];
        }
        cout << el;
        if (!spec) {
            cout << el;
        }
        cout << "\n";
    }
    return 0;
}