#include <bits/stdc++.h>

using namespace std;
const int c=20;
int w, n, k, t[c], db[c], cnt;
bool jo=0;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s >> k;
        n=s.size();
        for (int i=1; i<=n; i++) {
            t[i]=(s[i-1]-'0');
        }
        for (int i=1; i<=n; i++) {
            db[t[i]]++;
            if (db[t[i]]==1) {
                cnt++;
            }
            if (cnt>k) {
                int pos=i;
                while (!jo) {
                    for (int j=t[pos]+1; j<=9; j++) {
                        int a=(db[t[pos]]==1), b=(db[j]==0);
                        if (!jo && cnt-a+b<=k) {
                            db[t[pos]]--;
                            t[pos]=j;
                            db[j]++;
                            int mini=0;
                            while (cnt-a+b==k && !db[mini]) {
                                mini++;
                            }
                            for (int k=pos+1; k<=n; k++) {
                                t[k]=mini;
                            }
                            jo=1;
                        }
                    }
                    db[t[pos]]--;
                    if (!db[t[pos]]) {
                        cnt--;
                    }
                    pos--;
                }
                break;
            }
            if (i==n && cnt<=k) {
                jo=1;
            }
        }
        if (!jo) {
            if (t[1]!=9) {
                t[1]++;
                for (int i=2; i<=n; i++) {
                    t[i]=0;
                }
                jo=1;
            } else {
                cout << 1;
                for (int i=1; i<=n; i++) {
                    cout << 0;
                }
                cout << "\n";
            }
        }
        if (jo) {
            for (int i=1; i<=n; i++) {
                cout << t[i];
            }
            cout << "\n";
        }

        jo=0, cnt=0;
        for (int i=0; i<10; i++) {
            db[i]=0;
        }

    }
    return 0;
}
/*
1
998244353 1
*/