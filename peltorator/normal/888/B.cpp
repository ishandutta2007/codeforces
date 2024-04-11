#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 300001;

int a[N];

int main()
{
   // freopen("in.txt", "r", stdin);
 //   cout.precision(100);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            x++;
        else if (s[i] == 'L')
            x--;
        else if (s[i] == 'U')
            y++;
        else
            y--;
    }
    cout << n - abs(x) - abs(y);
    return 0;
}