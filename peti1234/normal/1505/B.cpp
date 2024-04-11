#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin >> n;
    cout << (n%9 ? n%9 : 9) << "\n";
    return 0;
}