#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, bal[c], jobb[c], fbal[c], fjobb[c], kis[c], nagy[c];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        cin >> s;
        for (int i=1; i<=n; i++) {
            bal[i]=0, jobb[i]=0;
            fbal[i]=0, fjobb[i]=0;
            kis[i]=0, nagy[i]=0;
        }
        for (int i=2; i<=n; i++) {
            if (s[i-2]=='<') {
                bal[i]=bal[i-1]+1;
            } else {
                fbal[i]=fbal[i-1]+1;
            }
        }
        for (int i=n-1; i>=1; i--) {
            if (s[i-1]=='>') {
                jobb[i]=jobb[i+1]+1;
            } else {
                fjobb[i]=fjobb[i+1]+1;
            }
        }
        int rem=n;
        for (int i=1; i<=n; i++) {
            if (!bal[i] && !jobb[i]) {
                for (int j=i-fbal[i]; j<i; j++) {
                    if (!kis[j]) {
                        kis[j]=rem--;
                    }
                }
                for (int j=i+fjobb[i]; j>i; j--) {
                    if (!kis[j]) {
                        kis[j]=rem--;
                    }
                }
                kis[i]=rem--;
            }
        }
        for (int i=1; i<=n; i++) {
            cout << kis[i] << " ";
        }
        cout << "\n";

        for (int i=1; i<=n; i++) {
            if (!fbal[i] && !fjobb[i]) {
                for (int j=i-bal[i]; j<i; j++) {
                    if (!nagy[j]) {
                        nagy[j]=++rem;
                    }
                }
                for (int j=i+jobb[i]; j>i; j--) {
                    if (!nagy[j]) {
                        nagy[j]=++rem;
                    }
                }
                nagy[i]=++rem;
            }
        }
        for (int i=1; i<=n; i++) {
            cout << nagy[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}