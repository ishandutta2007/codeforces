#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int n, t[c], p[c], db[c], l=1, sok, mini=INT_MAX;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        if (!p[i]) {
            for (int j=i; j<=n; j++) {
                if (t[i]==t[j]) {
                    p[j]=l;
                    db[l]++;
                    if (db[l]>1) {
                        sok++;
                    }
                }
            }
            l++;
        }
    }
    int x=0, y=1;
    while(x<=n) {
        if (!sok) {
            mini=min(mini, x-y+1);
            if (mini==0) {
                cout << 0 << endl;
                return 0;
            }
            db[p[y]]++;
            if (db[p[y]]>1) {
                sok++;
            }
            y++;
        } else {
            x++;
            db[p[x]]--;
            if (db[p[x]]>=1) {
                sok--;
            }
        }
    }
    if (!sok) {
        mini=min(mini, x-y+1);
    }
    cout << mini << endl;
    return 0;
}