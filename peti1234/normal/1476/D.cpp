#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int w, n, bal[c], jobb[c];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        cin >> s;
        bal[0]=0;
        bal[1]=(s[0]=='L');
        for (int i=2; i<=n; i++) {
            if (s[i-1]=='R') {
                bal[i]=0;
            } else if (s[i-2]=='L') {
                bal[i]=1;
            } else {
                bal[i]=bal[i-2]+2;
            }
        }
        jobb[n]=0;
        jobb[n-1]=(s[n-1]=='R');
        for (int i=n-2; i>=0; i--) {
            if (s[i]=='L') {
                jobb[i]=0;
            } else if (s[i+1]=='R') {
                jobb[i]=1;
            } else {
                jobb[i]=jobb[i+2]+2;
            }
        }
        for (int i=0; i<=n; i++) {
            cout << bal[i]+jobb[i]+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}