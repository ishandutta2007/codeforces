#include <bits/stdc++.h>

using namespace std;
long long w, n, d, r, x, y, ans;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        cin >> s;
        ans=n*n;
        for (auto x:s) {
            if (x=='D') d++;
            else r++;
        }
        x=1, y=1;
        bool jo=0;
        for (auto p:s) {
            if (p=='R') {
                if (!jo) {
                    ans-=(x-1)*(n-r);
                    y+=n-r;
                    jo=1;
                } else {
                    ans-=x-1;
                    y++;
                }
            } else {
                x++;
            }
        }

        x=1, y=1;
        jo=0;
        for (auto p:s) {
            if (p=='D') {
                if (!jo) {
                    ans-=(y-1)*(n-d);
                    x+=n-d;
                    jo=1;
                } else {
                    ans-=y-1;
                    x++;
                }
            } else {
                y++;
            }
        }

        if (!d || !r) {
            ans=n;
        }

        cout << ans << "\n";

        d=0, r=0, ans=0;
    }
    return 0;
}