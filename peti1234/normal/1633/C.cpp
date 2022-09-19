#include <bits/stdc++.h>

using namespace std;
long long w, dc, ac, dm, am, k, att, def;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> dc >> ac >> dm >> am >> k >> att >> def;
        bool jo=0;
        for (int i=0; i<=k; i++) {
            long long ac2=ac+att*i, dc2=dc+def*(k-i);
            if ((dm+ac2-1)/ac2<=(dc2+am-1)/am) jo=1;
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}