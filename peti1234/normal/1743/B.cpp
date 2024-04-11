#include <iostream>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        for (int i=2; i<=n; i++) cout << i << " ";
        cout << 1 << "\n";
    }
    return 0;
}