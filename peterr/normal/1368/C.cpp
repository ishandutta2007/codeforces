#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int num = 6 + (n - 1) * 3 + 1;
    cout << num << "\n";
    cout << "0 0\n";
    cout << "1 0\n";
    cout << "0 1\n";
    cout << "1 1\n";
    cout << "1 2\n";
    cout << "2 1\n";
    int x = 2, y = 2;
    for (int i = 0; i < n - 1; i++)
    {
        cout << x << " " << y << "\n";
        cout << x << " " << y + 1 << "\n";
        cout << x + 1 << " " << y << "\n";
        x++;
        y++;
    }
    cout << x << " " << y << "\n";
    return 0;
}