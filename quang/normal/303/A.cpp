#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY
#define LIMIT 100010

using namespace std;

int n;

int main()
{
    //filein, fileout;
    scanf("%d", &n);
    if(n % 2 == 0)
        cout << -1;
    else
    {
        for(int i = 0; i < n; i++) printf("%d ", i);
        cout << endl;
        for(int i = 0; i < n; i++) printf("%d ", i);
        cout << endl;
        for(int i = 0; i < n; i++) printf("%d ", 2 * i % n);
    }
    return 0;
}