#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = (int) s.length();
    cout << "3\n";
    cout << "L 2\n";
    n++;
    cout << "R 2\n";
    n += n - 2;
    cout << "R " << n - 1 << "\n";
    return 0;
}