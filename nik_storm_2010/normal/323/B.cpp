#include<iostream>

using namespace std;
const int N = 1000;

int main()
{
    int a[N+10][N+10];
    int n,x,y;
    cin >> n;
    if (n == 4) { cout << "-1" << endl; return 0; }
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) a[i][j] = 1;
    if (n % 2 == 1)
    {
        x = n; y = 1;
        while (x > y)
        {
            a[x][y] = 1; a[y][x] = 0;
            x -= 1; y += 1;
        }
    }
    else
    {
        a[n][1] = 1; a[1][n] = 0;
        x = n - 1; y = 2;
        while (x > y)
        {
            a[x][y-1] = 1; a[y-1][x] = 0;
            a[x+1][y] = 1; a[y][x+1] = 0;
            x -= 1; y += 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}