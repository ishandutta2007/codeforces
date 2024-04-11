#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << 1 << " " << (n%3==2 ? 2 : 1) << " " << (n%3==2 ? n-3 : n-2) << endl;
    return 0;
}