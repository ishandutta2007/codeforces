#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <sstream>
#include <vector>
#define maxn 110
#define oo
#define X first
#define Y second
#define FOR(i, a, b) for(int i = (a); i <= (b);i++)
#define FORN(i, a, b) for(int i = (a); i >= (b);i--)
#define filein "A.inp"
#define fileout "A.out"

using namespace std;

int tong1, tong2, n;

void nhap()
{
    FOR(i, 1, 3)
    {
        int x;
        cin >> x;
        tong1 += x;
    }
    FOR(i, 1, 3)
    {
        int x;
        cin >> x;
        tong2 += x;
    }
    cin >> n;
}

void xuli()
{
    double sum1 = ceil(1.0   * tong1 / 5);
    double sum2 = ceil(1.0 * tong2 / 10);
    if(n >= sum1 + sum2) cout << "YES";
    else cout << "NO";
}

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    nhap();
    xuli();
    return 0;
}