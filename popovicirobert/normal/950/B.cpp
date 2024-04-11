#include <bits/stdc++.h>

using namespace std;

const int nmax = 200005;
int a[nmax],b[nmax];
bool checka[nmax],checkb[nmax];

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    for(int j = 1;j <= m;j ++)
        cin >> b[j];
    int i = 1,j = 1,sa = 0,sb = 0,nsol = 0;
    while(i <= n || j <= m)
    {
        if(checka[i] == 0){
        sa += a[i];
        checka[i] = 1;
        }
        if(checkb[j] == 0){
        sb += b[j];
        checkb[j] = 1;
        }
        if(sa == sb)
        {
            nsol ++;
            sa = 0;
            sb = 0;
        }
        if(sa <= sb)
            i ++;
        if(sa >= sb)
            j ++;
    }
    cout << nsol;
    return 0;
}