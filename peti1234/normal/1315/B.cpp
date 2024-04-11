#include <bits/stdc++.h>

using namespace std;
long long w, n, a, b, p, sum, ans;
string s;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b >> p;
        cin >> s;
        n=s.size();
        sum=0, ans=1;
        for (int i=n-2; i>=0; i--) {
            if (i==n-2 || s[i]!=s[i+1]) {
                if (s[i]=='A') {
                    sum+=a;
                } else {
                    sum+=b;
                }
            }
            if (sum>p) {
                ans=i+2;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}