#include <iostream>
#include <cmath>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;

    int i, j;
    for(i = 2; i*i <= m; ++i)
    {
        if(m % i == 0)
        {
            cout << "NO";
            return 0;
        }
    }
    bool ex;
    for(i = n + 1; i < m; ++i)
    {
        ex = true;
        for(j = 2; j*j <= i; ++j)
        {
            if(i % j == 0)
            {
                ex = false;
            }
        }
        if(ex == true)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}