#include <bits/stdc++.h>

using namespace std;
int w, n, a, b, h, sum;
string s;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> a >> b >> h, sum=0;
        cin >> s;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') sum+=min(a, b+h);
            else sum+=min(b, a+h);
        }
        cout << sum << "\n";
    }
    return 0;
}