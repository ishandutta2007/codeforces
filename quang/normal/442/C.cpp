#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY
#define LIMIT 500010

using namespace std;

int n, top = 0;
long long kq = 0;
int a[LIMIT];

int main()
{
   // filein, fileout;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[++top]);
        while(top > 2 && a[top - 1] <= min(a[top - 2], a[top]))
        {
            kq += min(a[top - 2], a[top]);
            a[top - 1] = a[top--];
        }
    }
    for(int i = 2; i < top; i++) kq += min(a[i - 1], a[i + 1]);
    cout << kq;
}