#include <bits/stdc++.h>

using namespace std;
const int c=402;
int w, n, s1, s2, o1, o2;
char s[c][c];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        s1=s2=o1=o2=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                char k;
                cin >> k;
                s[i][j]=k;
                if (k=='*') {
                    if (!s1) {
                        s1=i, o1=j;
                    } else {
                        s2=i, o2=j;
                    }
                }
            }
        }
        if (s1==s2) {
            if (s1==1) {
                s1=2;
            } else {
                s1=1;
            }
            s2=s1;
        }
        if (o1==o2) {
            if (o1==1) {
                o1=2;
            } else {
                o1=1;
            }
            o2=o1;
        }
        s[s1][o2]='*', s[s2][o1]='*';
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << s[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}