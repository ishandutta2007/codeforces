#include <iostream>

using namespace std;

int main ()
{
    int w;

    cin >> w;

    cout << (w & 1 || w < 4 ? "NO" : "YES") << endl;

    return 0;
}