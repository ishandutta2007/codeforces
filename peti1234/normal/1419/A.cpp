#include <bits/stdc++.h>

using namespace std;
int w, n, p;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> s, p=0;
        for (int i=0; i<n; i++) {
            int x=s[i]-'0';
            if (n%2 && i%2==0 && x%2) p=1;
            if (n%2==0 && i%2 && x%2==0) p=1;
        }
        if (p%2==n%2) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
    return 0;
}