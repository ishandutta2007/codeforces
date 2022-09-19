#include <bits/stdc++.h>

using namespace std;
long long w, n, k, pos;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k >> s;
        pos=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') {
                long long mini=min(k, i-pos);
                k-=mini;
                swap(s[i], s[i-mini]);
                pos++;
            }
        }
        cout << s << "\n";
    }
    return 0;
}