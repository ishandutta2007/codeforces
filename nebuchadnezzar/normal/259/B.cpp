#include <cstdio>
#include <iostream>

using namespace std;

int mas[3][3], i, j, a, b, c, q1, q2, q3, cons;

int main()
{
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            cin >> mas[i][j];
        }
    }
    a = mas[0][1] + mas[0][2];
    b = mas[1][0] + mas[1][2];
    c = mas[2][1] + mas[2][0];
    //cout << a << " " << b << " " << c << endl;
    if(max(max(a, b), c) == a)
    {
        q1 = 1;
        q2 = a + 1 - b;
        q3 = a + 1 - c;
    }
    else if(max(max(a, b), c) == b)
    {
        q1 = b + 1 - a;
        q2 = 1;
        q3 = b + 1 - c;
    }
    else 
    {
        q1 = c + 1 - a;
        q2 = c + 1 - b;
        q3 = 1;
    } 
    
    cons = (a - q2 - q3) / 2;
    q1 += cons;
    q2 += cons;
    q3 += cons;
    mas[0][0] = q1;
    mas[1][1] = q2;
    mas[2][2] = q3;

    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}