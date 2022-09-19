#include <bits/stdc++.h>

using namespace std;
int t=INT_MAX, b=0, r, l=INT_MAX;
int n, m;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            if (s[j]=='B') {
                r=j+1;
                b=i;
                t=min(t, i);
                l=min(l, j+1);
            }
        }
    }
    cout << (t+b)/2 << " " << (r+l)/2 << endl;
    return 0;
}