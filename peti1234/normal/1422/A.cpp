#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    cin >> w;
    while(w--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << max({a, b, c}) << endl;
    }
    return 0;
}