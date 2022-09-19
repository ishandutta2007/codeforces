#include <bits/stdc++.h>

using namespace std;
int w, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        int mini=abs(a-b)/2, maxi=a+b-mini, s=2-(a+b)%2;
        cout << (maxi-mini)/s+1 << "\n";
        for (int i=mini; i<=maxi; i+=s) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}