#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY
#define LIMIT 100010

using namespace std;

int n, m, k;
int a[LIMIT], b[LIMIT];
bool check = 0;

int main()
{
    //filein, fileout;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    for(int i = 0; i < m; i++) scanf("%d", b + i);
    sort(a, a + n);
    sort(b, b + m);
    if(n > m) check = 1;
    else
    {
        for(int i = 0; i < n; i++)
        if(a[i] > b[m - n + i])
        {
            check = 1;
            break;
        }
    }
    cout << (check? "YES" : "NO");
    return 0;
}