#include <bits/stdc++.h>

using namespace std;
int w, n;
string s, p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        p.clear();
        while (true) {
            int db=0;
            while (p.size()>0 && p.back()=='z') {
                p.pop_back();
                db++;
            }
            if (p.size()==0) {
                p+="a";
            } else {
                p.back()++;
            }
            for (int i=0; i<db; i++) {
                p+="a";
            }
            int si=p.size(), jo=0;
            for (int i=0; i<n-si+1; i++) {
                if (s.substr(i, si)==p) {
                    jo=1;
                }
            }
            if (!jo) {
                break;
            }
        }
        cout << p << "\n";
    }
    return 0;
}
/*
1
28
qaabzwsxedcrfvtgbyhnujmiklop
*/