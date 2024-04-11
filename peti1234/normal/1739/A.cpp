#include <iostream>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int a, b;
        cin >> a >> b;
        cout << (a+1)/2 << " " << (b+1)/2 << "\n";
    }
    return 0;
}