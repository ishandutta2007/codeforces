#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int a, b;
        cin >> a >> b;
        cout << (a^b) << endl;
    }
    return 0;
}