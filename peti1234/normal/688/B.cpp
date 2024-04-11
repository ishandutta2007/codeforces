#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string n;
    cin >> n;
    string x=n;

    reverse(x.begin(), x.end());
    cout << n << x << endl;

    return 0;
}