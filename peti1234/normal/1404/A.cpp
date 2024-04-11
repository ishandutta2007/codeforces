#include <bits/stdc++.h>

using namespace std;
int w, n, k, kul, a, b;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k >> s, kul=0, a=0, b=0;
        for (int i=0; i<k; i++) {
            int x=0, y=0;
            for (int j=i; j<n; j+=k) {
                if (s[j]=='0') x++;
                if (s[j]=='1') y++;
            }
            if (x && y) kul=1;
            if (x) a++;
            if (y) b++;
        }
        if (!kul && max(a, b)<=k/2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}