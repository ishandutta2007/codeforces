#include <bits/stdc++.h>

using namespace std;
int w, k, n, m, db[3];
string s[3];
bool jo[3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> k;
        m=3*k, n=2*k;
        for (int i=0; i<3; i++) {
            db[i]=0;
            cin >> s[i];
            for (int j=0; j<n; j++) {
                if (s[i][j]=='0') {
                    db[i]++;
                }
            }
            jo[i]=(db[i]>=k);
            //cout << i << " " << jo[i] << "\n";
        }
        if (jo[0]==jo[2]) {
            swap(s[1], s[2]);
            swap(db[1], db[2]);
            swap(jo[1], jo[2]);
        } else if (jo[1]==jo[2]) {
            swap(s[0], s[2]);
            swap(db[0], db[2]);
            swap(jo[0], jo[2]);
        }
        int p0=0, p1=0;
        //cout << "vege " << s[0] << " " << s[1] << " " << jo[0] << "\n";
        for (int i=0; i<m; i++) {
            if (jo[0]) {
                bool bal=(p0<n && s[0][p0]=='1'), jobb=(p1<n && s[1][p1]=='1');
                if (bal || jobb) {
                    cout << '1';
                    if (bal) {
                        p0++;
                    }
                    if (jobb) {
                        p1++;
                    }
                } else {
                    cout << '0';
                    p0++, p1++;
                }
            } else {
                bool bal=(p0<n && s[0][p0]=='0'), jobb=(p1<n && s[1][p1]=='0');
                if (bal || jobb) {
                    cout << '0';
                    if (bal) {
                        p0++;
                    }
                    if (jobb) {
                        p1++;
                    }
                } else {
                    cout << '1';
                    p0++, p1++;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
/*
1
2
1111
0000
1010

*/