#include <iostream>

using namespace std;

int n, i;

int main()
{
    cin >> n;
    if(n % 2 == 1)
    {
        cout << "-1";
    }
    else
    {
        for(i = n; i > 0; --i)
        {
            cout << i << " ";
        }
    }
    return 0;
}