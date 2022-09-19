#include <bits/stdc++.h>

using namespace std;
int w, n, mini;
string s;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> s;
        mini=1e9;
        for (int i=0; i<n-1; i++) {
            int aa=0, bb=0, cc=0;
            for (int j=0; j<20; j++) {
                if (i+j<n) {
                    if (s[i+j]=='a') aa++;
                    if (s[i+j]=='b') bb++;
                    if (s[i+j]=='c') cc++;
                }
                if (j>=1 && aa>bb && aa>cc) {
                    mini=min(mini, j+1);
                }
            }
        }
        cout << (mini==1e9 ? -1 : mini) << "\n";
    }
    return 0;
}
/*
1
4
abba
*/