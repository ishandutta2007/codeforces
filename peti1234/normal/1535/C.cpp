#include <bits/stdc++.h>

using namespace std;
int w, n, o0, o1, e0, e1;
string s;
long long ans=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        ans=0;
        n=s.size();
        o0=-1, o1=-1, e0=-2, e1=-2;
        for (int i=0; i<n; i++) {
            char c=s[i];
            if (c=='0') {
                if (i%2) {
                    o0=i;
                } else {
                    e0=i;
                }
            }
            if (c=='1') {
                if (i%2) {
                    o1=i;
                } else {
                    e1=i;
                }
            }
            //cout << "ertekek " << o0 << " " << o1 << " " << e0 << " " << e1 << "\n";
            int maxi=max({min(o0, o1), min(e0, e1), min(o0, e0), min(o1, e1)});
            //cout << i << " " << maxi << "\n";
            ans+=i-maxi;
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
1
0?10
*/