#include <bits/stdc++.h>

using namespace std;
int w, a, b;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        a=0, b=0;
        for (int i=0; i<10; i++) {
            if (i%2 && s[i]!='0' || i%2==0 && s[i]!='1') {
                a++;
            }
            if (i%2 && s[i]!='1' || i%2==0 && s[i]!='0') {
                b++;
            }
            if (a==6 || b==6 || i==9) {
                cout << i+1 << "\n";
                break;
            }
        }
    }
    return 0;
}