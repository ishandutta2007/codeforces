#include <bits/stdc++.h>

using namespace std;
int w, n, k;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k >> s;
        sort(s.begin(), s.end());
        if (s[0]!=s[k-1]) cout << s[k-1];
        else if (s[k]!=s[n-1]) {
            for (int i=k-1; i<n; i++) cout << s[i];
        } else {
            for (int i=0; i<n; i+=k) cout << s[i];
        }
        cout << endl;
    }
    return 0;
}