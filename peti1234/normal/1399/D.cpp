#include <bits/stdc++.h>

using namespace std;
int w, n, maxi, a, b, t[200002];
string s;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> s, maxi=0, a=0, b=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') {
                a++, t[i]=a;
                b=max(a, b);
            } else {
                if (a) t[i]=a, a--;
                else b++, t[i]=b;
            }
            maxi=max(maxi, b);
        }
        cout << maxi << "\n";
        for (int i=0; i<n; i++) cout << t[i] << " ";
        cout << "\n";
    }
    return 0;
}