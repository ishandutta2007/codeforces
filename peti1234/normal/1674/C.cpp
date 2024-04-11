#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        string a, b;
        cin >> a >> b;

        int da=0, db=0;
        for (auto x:a) {
            if (x=='a') da++;
        }
        for (auto x:b) {
            if (x=='a') db++;
        }
        if (b=="a" || da==0) {
            cout << 1 << "\n";
            continue;
        }
        if (da && db) {
            cout << -1 << "\n";
            continue;
        }
        long long ans=1;
        for (int i=1; i<=da; i++) ans*=2;
        cout << ans << "\n";
    }
    return 0;
}