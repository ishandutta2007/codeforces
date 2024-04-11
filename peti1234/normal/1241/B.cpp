#include <bits/stdc++.h>

using namespace std;
int w;
string a, b;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b;
        int jo=0;
        for (auto i:a) {
            for (auto j:b) {
                if (i==j) {
                    jo=1;
                }
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}