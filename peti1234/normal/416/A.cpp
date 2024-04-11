#include <bits/stdc++.h>

using namespace std;
int sok=1e9+5;
int n, kis=-sok, nagy=sok;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        string s, ans;
        int x;
        cin >> s >> x >> ans;
        if (s=="<=") x++;
        if (s==">=") x--;
        //cout << "fontos " << s[0] << " " << x << "\n";
        if (s[0]=='<') {
            if (ans=="Y") nagy=min(nagy, x);
            else kis=max(kis, x-1);
        }
        if (s[0]=='>') {
            if (ans=="Y") kis=max(kis, x);
            else nagy=min(nagy, x+1);
        }
    }
    if (nagy-kis<2) {
        cout << "Impossible\n";
    } else {
        cout << kis+1 << "\n";
    }
    return 0;
}