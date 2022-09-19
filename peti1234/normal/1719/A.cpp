#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int a, b;
        cin >> a >> b;
        cout << ((a+b)%2 ? "Burenka" : "Tonya") << "\n";
    }
    return 0;
}