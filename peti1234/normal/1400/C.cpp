#include <bits/stdc++.h>

using namespace std;
int w, n, x, h;
string s;
bool t[100002];
int main()
{
    cin >> w;
    while(w--) {
        cin >> s >> x, n=s.size(), h=0;
        for (int i=0; i<n; i++) t[i]=1;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') {
                if (i>=x) t[i-x]=0;
                if (i+x<n) t[i+x]=0;
            }
        }
        for (int i=0; i<n; i++) if (s[i]=='1') if ((i<x || t[i-x]==0) && (i+x>=n || t[i+x]==0)) h=1;
        if (h) cout << -1;
        else for (int i=0; i<n; i++) cout << t[i];
        cout << "\n";
    }
    return 0;
}