#include <bits/stdc++.h>

using namespace std;
const int c=102;
int w, n, q;
string s;
bool ej[c], hj[c], a, b;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> q;
        for (int i=0; i<n; i++) {
            ej[i]=0, hj[i]=0, a=0, b=0;
        }
        cin >> s;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') {
                if (!a) a=1;
                else ej[i]=1;
            } else {
                if (!b) b=1;
                else ej[i]=1;
            }
        }
        a=0, b=0;
        for (int i=n-1; i>=0; i--) {
            if (s[i]=='0') {
                if (!a) a=1;
                else hj[i]=1;
            } else {
                if (!b) b=1;
                else hj[i]=1;
            }
        }
        while(q--) {
            int a, b; cin >> a >> b;
            a--, b--;
            if (ej[a] || hj[b]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}