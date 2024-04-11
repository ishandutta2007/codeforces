#include <bits/stdc++.h>

using namespace std;
int n, a, b, c, d;
string x, y, s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    a=x[0]-'a', b=x[1]-'a', c=y[0]-'a', d=y[1]-'a';
    cout << "YES\n";
    if (a==b || c==d) {
        if (a==b) {
            if ((c+1)%3!=d) {
                s+="abc";
            } else s+="cba";
        }
        else if (c==d) {
            if ((a+1)%3!=b) {
                s+="abc";
            } else s+="cba";
        }
        for (int i=0; i<n; i++) {
            cout << s;
        }
    } else {
        if (a==d && b==c) {
            if (a+b==1) {
                s+="acb";
            }
            if (a+b==2) {
                s+="abc";
            }
            if (a+b==3) {
                s+="bac";
            }
        } else {
            if (a && c) {
                s+="a";
                if ((a==1 && b==2) || (c==1 && d==2)) {
                    s+="cb";
                } else {
                    s+="bc";
                }
            }
            else if (a!=1 && c!=1) {
                s+="b";
                if ((a==0 && b==2) || (c==0 && d==2)) {
                    s+="ca";
                } else {
                    s+="ac";
                }
            }
            else if (a!=2 && c!=2) {
                s+="c";
                if ((a==0 && b==1) || (c==0 && d==1)) {
                    s+="ba";
                } else {
                    s+="ab";
                }
            }
        }
        for (int j=0; j<3; j++) {
            for (int i=0; i<n; i++) {
                cout << s[j];
            }
        }
    }
    cout << "\n";
    return 0;
}