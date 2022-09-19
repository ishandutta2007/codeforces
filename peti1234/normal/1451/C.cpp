#include <bits/stdc++.h>

using namespace std;
const int c=32;
int w, n, k, x[c], y[c];
string a, b;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> k;
        cin >> a >> b;
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        for (int i=0; i<c; i++) x[i]=0, y[i]=0;
        bool jo=1;
        for (int i=0; i<n; i++) {
            x[a[i]-'a']++;
            y[b[i]-'a']++;
            if (a[i]>b[i]) jo=0;
        }
        for (int i=0; i<c; i++) {
            int p=abs(x[i]-y[i]);
            if (p%k) jo=0;
        }
        if (jo) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}