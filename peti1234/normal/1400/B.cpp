#include <bits/stdc++.h>

using namespace std;
long long q, a, b, cs, cw, s, w, maxi;
int main()
{
    cin >> q;
    while(q--) {
        cin >> a >> b >> cs >> cw >> s >> w;
        if (s>w) swap(cs, cw), swap(s, w);
        if (a/s+b/s<=cs) cout << a/s+b/s << "\n";
        else {
            maxi=0;
            for (int i=0; i<=cs; i++) if (i*s<=a && (cs-i)*s<=b) maxi=max(maxi, min(cw, (a-i*s)/w+(b-(cs-i)*s)/w));
            cout << maxi+cs << "\n";
        }
    }
    return 0;
}
/*
1
33 27
6 10
5 6
*/