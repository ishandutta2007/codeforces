#include <bits/stdc++.h>

using namespace std;
int a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a;
    if (a==1) {
        cout << 1 << " " << 1 << endl << 1;
        return 0;
    }
    cout << 2*a-2 << " " << 2 << endl << 1 << " " << 2;
    return 0;
}