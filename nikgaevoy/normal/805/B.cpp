#include <iostream>

using namespace std;

int main ()
{
    int n;
    
    cin >> n;

    while (n --> 0)
        cout << char ('a' + (1 & (n ^ (n >> 1))));
    cout << endl;

    return 0;
}