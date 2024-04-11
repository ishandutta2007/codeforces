#include <iostream>

using namespace std;

int main()
{
    long long w, x, y;
    cin >> w;
    while (w--) {
        cin >> x >> y;
        cout << (x>y+1 ? "YES" : "NO") << "\n";
    }
    return 0;
}