#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, db=0, x;
        cin >> n;
        while (n--) {
            cin >> x;
            db+=x-1;
        }
        cout << (db%2 ? "errorgorn" : "maomao90") << "\n";
    }
    return 0;
}