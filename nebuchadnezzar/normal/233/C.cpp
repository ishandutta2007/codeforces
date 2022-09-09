#include <iostream>

using namespace std;

int k, n, i, j, num, num_edge, mas[100][100];

int main()
{
    for(i = 0; i < 100; ++i)
    {
        for(j = 0; j < 100; ++j)
        {
            mas[i][j] = 0;
        }
    }
    cin >> k;
    for(i = 3; i * (i - 1) * (i - 2) / 6 <= k; ++i)
    {
        n = 0;
    }
    n = i - 1;
    //cout << n;
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            if(i != j)
            {
                mas[i][j] = 1;
            }
        }
    }
    
    num = n * (n - 1) * (n - 2) / 6;
    //cout << num << endl;
    while(num < k)
    {
        num_edge = 0;
        for(i = 2; i * (i - 1) / 2 <= k - num; ++i)
        {
            num_edge = 0;
        }
        num_edge = i - 1;
        num += num_edge * (num_edge - 1) / 2;
        //cout << num_edge << "num_edge" << num << endl;
        for(i = 0; i < num_edge; ++i)
        {
            mas[n][i] = 1;
            mas[i][n] = 1;
        }
        n += 1;
    }
    cout << n << endl;
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            cout << mas[i][j];
        }
        cout << endl;
    }

    return 0;
}