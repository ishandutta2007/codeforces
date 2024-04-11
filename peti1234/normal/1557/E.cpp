#include <bits/stdc++.h>

using namespace std;
int w, x, y, p;
void lep() {
    cout << x << " " << y;
    cout.flush() << endl;
    string s;
    cin >> s;
    p=0;
    if (s[0]=='U') {
        p=2;
        return;
    }
    if (s[3]=='e') {
        p=1;
    }
    if (s[3]=='n') {
        p=3;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        x=1, y=0;
        while (true) {
            y++;
            lep();
            if (p==1) {
                break;
            }
            if (p==2 && y>1) {
                y=0;
            }
            if (p==3 || y==8) {
                x++;
                lep();
                if (p==1) {
                    break;
                }
                if (y>1) {
                    y=0;
                }
            }

        }
    }
    return 0;
}