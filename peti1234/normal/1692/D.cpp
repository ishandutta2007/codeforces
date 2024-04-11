#include <bits/stdc++.h>

using namespace std;
set<int> pal={0, 70, 140, 210, 280, 350, 601, 671, 741, 811, 881, 951, 1202, 1272, 1342, 1412};
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string s;
        int ert=0, x;
        cin >> s >> x;
        ert=600*(s[0]-'0')+60*(s[1]-'0')+10*(s[3]-'0')+(s[4]-'0');
        set<int> p;
        for (int i=0; i<1440; i++) {
            if (pal.find(ert)!=pal.end()) {
                p.insert(ert);
            }
            ert=(ert+x)%1440;
            if (i<10) {
                //cout << ert << "\n";
            }
        }

        cout << p.size() << "\n";
    }

    return 0;
}
/*
1
03:12 360
*/