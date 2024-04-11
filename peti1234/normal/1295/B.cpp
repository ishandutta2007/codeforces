#include <bits/stdc++.h>

using namespace std;
int w, n, ert, ert2, x;
map<int, int> m;
string s;


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> ert >> s;
        x=0, m.clear();
        m[0]=1;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') {
                x++;
            } else {
                x--;
            }
            if (i!=n-1) {
                m[x]++;
            }
        }
        //cout << "valasz: ";
        if (x==0) {
            if (m[ert]>0) {
                cout << -1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else {
            if (x>0) {
                ert2=ert-n;
                while (ert2%x) {
                    ert2--;
                }
                ert2=max(0, ert2);
            } else {
                ert2=ert+n;
                while (ert2%x) {
                    ert2++;
                }
                ert2=min(0, ert2);
            }
            int ans=0;
            //cout << x << " ";
            //cout << ert2 << "\n";
            for (int i=0; i<2*n; i++) {
                ans+=m[ert-ert2];
                if (abs(ert-ert2)>3*n) {
                    break;
                }
                //cout << "kul " << ert-ert2 << " " << m[ert-ert2] << "\n";
                ert2+=x;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
/*
1
5 3
10101
*/