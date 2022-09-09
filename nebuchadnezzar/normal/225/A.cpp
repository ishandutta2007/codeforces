#include <iostream>
#include <cmath>

using namespace std;

int gcd(int m, int n)
{
    
    if(n == 0)
    {   
        
        return m;
    }
    return gcd(n, m % n);
}

int n, x;
int mas[101][6];

int main()
{
    cin >> n;
    cin >> x;
    int a, b, i, j;
    for(i = 0; i < n; ++i)
    {
        cin >> a >> b;
        mas[i][a - 1] = 1;
        mas[i][b - 1] = 1;
        mas[i][7 - a - 1] = 1;
        mas[i][7 - b - 1] = 1;
    }

    

    for(i = 1; i < n; ++i)
    {
        for(j = 0; j < 6; ++j)
        {
            if(mas[i][j] != mas[0][j])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}