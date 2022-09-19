#include <bits/stdc++.h>

using namespace std;
int w, h, m, a, b, t[10];
string s;
int valt(char c) {
    return (c-'0');
}
bool jo() {
    int p=a/10, q=a%10, r=b/10, s=b%10;
    if (min({t[p], t[q], t[r], t[s]})==-1) {
        return false;
    }
    if (10*t[s]+t[r]>=h) {
        return false;
    }
    if (10*t[q]+t[p]>=m) {
        return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0; i<10; i++) {
        t[i]=-1;
    }
    t[0]=0, t[1]=1, t[2]=5, t[5]=2, t[8]=8;
    cin >> w;
    while (w--) {
        cin >> h >> m;
        cin >> s;
        a=10*valt(s[0])+valt(s[1]), b=10*valt(s[3])+valt(s[4]);
        while (!jo()) {
            b++;
            if (b==m) {
                b=0, a++;
                if (a==h) {
                    a=0;
                }
            }
        }
        if (a<10) {
            cout << 0;
        }
        cout << a << ":";
        if (b<10) {
            cout << 0;
        }
        cout << b << "\n";
    }
    return 0;
}