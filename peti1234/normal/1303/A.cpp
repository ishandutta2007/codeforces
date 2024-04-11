#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size();
        int cnt=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') {
                bool a=0, b=0;
                for (int j=0; j<i; j++) {
                    if (s[j]=='1') {
                        a=1;
                    }
                }
                for (int j=i+1; j<n; j++) {
                    if (s[j]=='1') {
                        b=1;
                    }
                }
                cnt+=(a&b);
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}