#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY
#define LIMIT

using namespace std;

string a, b;

int main()
{
  //  filein, fileout;
    cin >> a >> b;
    int n = a.size(), m = b.size(), x = 0, y = 0;
    for(int i = 0; i < (int)a.size(); i++) if(a[i] == '1') x++;
    for(int i = 0; i < (int)b.size(); i++) if(b[i] == '1') y++;
    if(x & 1) x++;
    cout << ( (x >= y)? "YES" : "NO");
    return 0;
}