#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (min(m, k) >= n)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}