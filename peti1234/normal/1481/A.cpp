#include <bits/stdc++.h>

using namespace std;
int w, db[4], x, y;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> y >> x;
        for (int i=0; i<4; i++) {
            db[i]=0;
        }
        cin >> s;
        for (char c:s) {
            if (c=='U') {
                db[0]++;
            }
            if (c=='D') {
                db[1]++;
            }
            if (c=='R') {
                db[2]++;
            }
            if (c=='L') {
                db[3]++;
            }
        }
        bool a=0, b=0;
        if (x==0 || (x>0 && db[0]>=x) || (x<0 && db[1]>=-x)) {
            a=1;
        }
        if (y==0 || (y>0 && db[2]>=y) || (y<0 && db[3]>=-y)) {
            b=1;
        }
        cout << (a&&b ? "YES" : "NO") << "\n";
    }
    return 0;
}